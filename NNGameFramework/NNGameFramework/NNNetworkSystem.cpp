
#include "NNNetworkSystem.h"

NNNetworkSystem* NNNetworkSystem::m_pInstance = nullptr;

NNNetworkSystem::NNNetworkSystem()
	: m_ServerIP(nullptr), m_Port(9001), 
	m_RecvBuffer(NNCircularBuffer(1024*4)),
	m_SendBuffer(NNCircularBuffer(1024*4))
{
}
NNNetworkSystem::~NNNetworkSystem()
{
	Destroy();
}

bool NNNetworkSystem::Init()
{
	int nResult = WSAStartup( MAKEWORD(2,2), &m_WSAData );
	if ( nResult != 0 )
	{
		return false;
	}

	m_Socket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	u_long arg = 1 ;
	::ioctlsocket(m_Socket, FIONBIO, &arg) ;

	int opt = 1 ;
	::setsockopt(m_Socket, IPPROTO_TCP, TCP_NODELAY, (const char*)&opt, sizeof(int)) ;

	if ( m_Socket == INVALID_SOCKET )
	{
		return false;
	}

	
	//SetPacketFunction(PKT_SC_CHAT,TestChatResultPacketFunction);

	return true;
}

void NNNetworkSystem::Destroy()
{
}

bool NNNetworkSystem::Connect( const char* serverIP, int port )
{
	struct hostent* host;

	if ( (host=gethostbyname(serverIP)) == NULL )
	{
		return false;
	}

	SOCKADDR_IN SockAddr;
	SockAddr.sin_port = htons(port);
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

	if ( SOCKET_ERROR == connect(m_Socket, (LPSOCKADDR)(&SockAddr), sizeof(SockAddr)) )
	{
		if ( GetLastError() != WSAEWOULDBLOCK )
		{
			return false;
		}
	}
	
	return PostRecv() ;
}
bool NNNetworkSystem::PostRecv()
{
	DWORD recvbytes = 0 ;
	DWORD flags = 0 ;
	WSABUF buf ;
	buf.len = (ULONG)m_RecvBuffer.GetFreeSpaceSize() ;
	buf.buf = (char*)m_RecvBuffer.GetBuffer() ;

	memset(&m_OverlappedRecv, 0, sizeof(OVERLAPPED)) ;
	/// 비동기 입출력 시작
	if ( SOCKET_ERROR == WSARecv(m_Socket, &buf, 1, &recvbytes, &flags, &m_OverlappedRecv, RecvCompletion) )
	{
		int error = WSAGetLastError();
		if ( error != WSA_IO_PENDING )
			return false ;
	}
	return true;
}
void NNNetworkSystem::OnRead(size_t len)
{
	m_RecvBuffer.Commit(len);
	while ( true )
	{
		NNPacketHeader header;

		if ( false ==  m_RecvBuffer.Peek((char*)&header, sizeof(NNPacketHeader)) )
		{
			break;
		}

		if ( (header.m_Size - sizeof(NNPacketHeader)) > m_RecvBuffer.GetStoredSize() )
		{
			break;
		}

		m_PacketFunction[header.m_Type](header);
	}
}

bool NNNetworkSystem::Send(NNPacketHeader* pkt)
{

	/// 버퍼 용량 부족인 경우는 끊어버림
	if ( false == m_SendBuffer.Write((char*)pkt, pkt->m_Size) )
	{
		return false ;
	}

	/// 보낼 데이터가 있는지 검사
	if ( m_SendBuffer.GetContiguiousBytes() == 0 )
	{
		/// 방금전에 write 했는데, 데이터가 없다면 뭔가 잘못된 것
		return false ;
	}	
	DWORD sendbytes = 0 ;
	DWORD flags = 0 ;

	WSABUF buf ;
	buf.len = (ULONG)m_SendBuffer.GetContiguiousBytes() ;
	buf.buf = (char*)m_SendBuffer.GetBufferStart() ;


	memset(&m_OverlappedSend, 0, sizeof(OVERLAPPED)) ;

	// 비동기 입출력 시작
	if ( SOCKET_ERROR == WSASend(m_Socket, &buf, 1, &sendbytes, flags, &m_OverlappedSend, SendCompletion) )
	{
		DWORD error = WSAGetLastError();
		printf_s("%d",error);
		if ( error != WSA_IO_PENDING )
			return false ;
	}

	return true ;
}
void NNNetworkSystem::OnWriteComplete(size_t len)
{
	m_SendBuffer.Remove(len);
}

void NNNetworkSystem::SetPacketFunction( short packetType, void(Function)(NNPacketHeader&) )
{
	m_PacketFunction[packetType] = Function;
}

NNNetworkSystem* NNNetworkSystem::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new NNNetworkSystem();
	}

	return m_pInstance;
}
void NNNetworkSystem::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
	}
}

///////////////////////////////////////////////////////////

void CALLBACK RecvCompletion(DWORD dwError, DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags)
{
	/// 에러 발생시 해당 세션 종료
	if ( dwError || cbTransferred == 0 )
	{
		return ;
	}

	/// 받은 데이터 처리
	NNNetworkSystem::GetInstance()->OnRead(cbTransferred);

	/// 다시 받기
	if ( false == NNNetworkSystem::GetInstance()->PostRecv() )
	{
		return ;
	}
}

void CALLBACK SendCompletion(DWORD dwError, DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags)
{
	/// 에러 발생시 해당 세션 종료
	if ( dwError || cbTransferred == 0 )
	{
		return ;
	}

	NNNetworkSystem::GetInstance()->OnWriteComplete(cbTransferred) ;
}
