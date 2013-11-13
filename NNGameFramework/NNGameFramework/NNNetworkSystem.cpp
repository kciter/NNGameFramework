
#include "NNNetworkSystem.h"
#include "NNApplication.h"

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
	WSADATA WsaDat ;

	int nResult = WSAStartup(MAKEWORD(2,2),&WsaDat) ;
	if ( nResult != 0 )
		return false ;

	m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) ;
	if ( m_Socket == INVALID_SOCKET )
		return false ;

	nResult = WSAAsyncSelect(NNNetworkSystem::GetInstance()->m_Socket, NNApplication::GetInstance()->GetHWND(), WM_SOCKET,(FD_CLOSE|FD_CONNECT));
	if (nResult)
	{
		MessageBox(NNApplication::GetInstance()->GetHWND(), L"WSAAsyncSelect failed", L"Critical Error", MB_ICONERROR);
		SendMessage(NNApplication::GetInstance()->GetHWND(),WM_DESTROY,NULL,NULL);
		return false;
	}

	return true ;
}

void NNNetworkSystem::Destroy()
{
	for (auto& iter=m_PacketHandler.begin(); iter!=m_PacketHandler.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	m_PacketHandler.clear();
}

bool NNNetworkSystem::Connect( const char* serverIP, int port )
{
	// Resolve IP address for hostname
	struct hostent* host ;

	if ( (host=gethostbyname(serverIP) ) == NULL )
		return false ;

	// Set up our socket address structure
	SOCKADDR_IN SockAddr ;
	SockAddr.sin_port = htons(port) ;
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr) ;

	if ( SOCKET_ERROR == connect(m_Socket, (LPSOCKADDR)(&SockAddr), sizeof(SockAddr)) )
	{
		if (GetLastError() != WSAEWOULDBLOCK )
			return false ;
	}

	return true ;
}
void NNNetworkSystem::ProcessPacket()
{
	while ( true )
	{
		NNPacketHeader header;

		if ( m_RecvBuffer.Peek((char*)&header, sizeof(NNPacketHeader)) == false )
		{
			break;
		}

		if ( header.m_Size > m_RecvBuffer.GetCurrentSize() ) /// warning
		{
			break;
		}

		m_PacketHandler[header.m_Type]->HandlingPacket(header.m_Type, &m_RecvBuffer, &header);
	}
}

void NNNetworkSystem::Write( const char* data, size_t size )
{
	if ( m_SendBuffer.Write(data, size) )
	{
		PostMessage(NNApplication::GetInstance()->GetHWND(), WM_SOCKET, NULL, FD_WRITE) ;
	}
}

void NNNetworkSystem::Read()
{
	char inBuf[4096] = {0, } ;

	int recvLen = recv(m_Socket, inBuf, 4096, 0) ;

	if ( !m_RecvBuffer.Write(inBuf, recvLen) )
	{
		/// ¹öÆÛ ²ËÃ¡´Ù. 
		//assert(false) ;
	}
	else
	{
		ProcessPacket() ;
	}

	
}

void NNNetworkSystem::SetPacketHandler( short packetType, NNBaseHandler* handler )
{
	m_PacketHandler[packetType] = handler;
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