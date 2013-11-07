
#include "NNNetworkSystem.h"

NNNetworkSystem* NNNetworkSystem::m_pInstance = nullptr;

NNNetworkSystem::NNNetworkSystem()
	: m_ServerIP(nullptr), m_Port(9001)
{
}
NNNetworkSystem::~NNNetworkSystem()
{

}

bool NNNetworkSystem::Init()
{
	int nResult = WSAStartup( MAKEWORD(2,2), &m_WSAData );
	if ( nResult != 0 )
	{
		return false;
	}

	m_Socket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if ( m_Socket == INVALID_SOCKET )
	{
		return false;
	}

	return true;
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

	return true;
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