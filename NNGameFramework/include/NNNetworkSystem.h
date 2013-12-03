
/**
 * NNNetworkSystem.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNConfig.h"
#include "NNPacketHeader.h"
#include "NNCircularBuffer.h"
#include "NNBaseHandler.h"
#include <map>

class NNNetworkSystem
{
public:
	friend class NNApplication;

	static NNNetworkSystem* GetInstance();
	static void ReleaseInstance();

	bool Init();
	void Destroy();
	bool Connect( const char* serverIP, int port );
	
	void SetPacketHandler( short packetType, NNBaseHandler* handler );
	
	void Write( const char* data, size_t size );
	void Read();

private:
	void ProcessPacket();

private:
	SOCKET m_Socket;

	SOCKADDR_IN m_ServerAddr;

	char* m_ServerIP;
	int m_Port;

	NNCircularBuffer m_RecvBuffer;
	NNCircularBuffer m_SendBuffer;

	std::map<short,NNBaseHandler*> m_PacketHandler;

private:
	static NNNetworkSystem* m_pInstance;

	NNNetworkSystem();
	~NNNetworkSystem();
};