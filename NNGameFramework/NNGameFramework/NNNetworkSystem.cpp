
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

	return true ;
}

void NNNetworkSystem::Destroy()
{
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

	/// NAGLE 끈다
	/// NAGLE Algorithm
	/// http://en.wikipedia.org/wiki/Nagle's_algorithm
	int opt = 1 ;
	::setsockopt(m_Socket, IPPROTO_TCP, TCP_NODELAY, (const char*)&opt, sizeof(int)) ;

	return true ;
}
void NNNetworkSystem::ProcessPacket()
{
	while ( true )
	{
		NNPacketHeader header;

		if ( m_RecvBuffer.Peek((char*)&header, sizeof(NNPacketHeader)) )
		{
			break;
		}

		if ( header.m_Size > m_RecvBuffer.GetCurrentSize() ) /// 문제 생길 것 같은 느낌
		{
			break;
		}

		m_PacketHandler[header.m_Type]->HandlingPacket(header.m_Type);
	}
}

void NNNetworkSystem::Read()
{
	char inBuf[4096] = {0, } ;

	int recvLen = recv(m_Socket, inBuf, 4096, 0) ;

	if ( !m_RecvBuffer.Write(inBuf, recvLen) )
	{
		/// 버퍼 꽉찼다. 
		assert(false) ;
	}

	ProcessPacket() ;
}

void NNNetworkSystem::Write()
{
	int size = m_SendBuffer.GetCurrentSize() ;
	if ( size > 0 )
	{
		char* data = new char[size] ;
		m_SendBuffer.Peek(data) ;

		int sent = send(m_Socket, data, size, 0) ;

		/// 다를수 있다
		if ( sent != size )
			OutputDebugStringA("sent != request\n") ;

		m_SendBuffer.Consume(sent) ;

		delete [] data ;
	}
}

void NNNetworkSystem::Close()
{
	closesocket(m_Socket);
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