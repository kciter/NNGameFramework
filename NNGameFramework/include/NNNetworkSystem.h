
#pragma once

#include <WinSock2.h>

class NNNetworkSystem
{
private:
	static NNNetworkSystem* m_pInstance;

private:
	NNNetworkSystem();
	~NNNetworkSystem();

public:
	static NNNetworkSystem* GetInstance();
	static void ReleaseInstance();

private:
	WSADATA m_WSAData;
	SOCKET m_Socket;

	SOCKADDR_IN m_ServerAddr;

	char* m_ServerIP;
	int m_Port;

public:
	bool Init();
	bool Connect( const char* serverIP, int port );
};