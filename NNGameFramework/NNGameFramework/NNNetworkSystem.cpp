
/**
 * NNNetworkSystem.cpp
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNNetworkSystem.h"
#include "NNApplication.h"

NNNetworkSystem* NNNetworkSystem::mpInstance = nullptr;

NNNetworkSystem::NNNetworkSystem()
	: mServerIP(nullptr), mPort(9001), 
	mRecvBuffer(NNCircularBuffer(1024*10)),
	mSendBuffer(NNCircularBuffer(1024*10))
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

	mSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) ;
	if ( mSocket == INVALID_SOCKET )
		return false ;

	nResult = WSAAsyncSelect(NNNetworkSystem::GetInstance()->mSocket, NNApplication::GetInstance()->GetHWND(), WM_SOCKET,(FD_CLOSE|FD_CONNECT));
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
	for (auto& iter=mPacketHandler.begin(); iter!=mPacketHandler.end(); iter++ )
	{
		SafeDelete( iter->second );
		iter->second = nullptr;
	}
	mPacketHandler.clear();
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

	if ( SOCKET_ERROR == connect(mSocket, (LPSOCKADDR)(&SockAddr), sizeof(SockAddr)) )
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

		if ( mRecvBuffer.Peek((char*)&header, sizeof(NNPacketHeader)) == false )
		{
			break;
		}

		if ( header.mSize > mRecvBuffer.GetCurrentSize() ) /// warning
		{
			break;
		}

		mPacketHandler[header.mType]->HandlingPacket(header.mType, &mRecvBuffer, &header);
	}
}

void NNNetworkSystem::Write( const char* data, size_t size )
{
	if ( mSendBuffer.Write(data, size) )
	{
		PostMessage(NNApplication::GetInstance()->GetHWND(), WM_SOCKET, NULL, FD_WRITE) ;
	}
}

void NNNetworkSystem::Read()
{
	char inBuf[4096] = {0, } ;

	int recvLen = recv(mSocket, inBuf, 4096, 0) ;

	if ( !mRecvBuffer.Write(inBuf, recvLen) )
	{
		/// 버퍼 꽉찼다. 
		//assert(false) ;
	}
	else
	{
		ProcessPacket() ;
	}
}

void NNNetworkSystem::SetPacketHandler( short packetType, NNBaseHandler* handler )
{
	mPacketHandler[packetType] = handler;
}

NNNetworkSystem* NNNetworkSystem::GetInstance()
{
	if ( mpInstance == nullptr )
	{
		mpInstance = new NNNetworkSystem();
	}

	return mpInstance;
}
void NNNetworkSystem::ReleaseInstance()
{
	if ( mpInstance != nullptr )
	{
		delete mpInstance;
	}
}