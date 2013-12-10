
/**
 * NNNetworkSystem.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 08
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
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
	SOCKET mSocket;

	SOCKADDR_IN mServerAddr;

	char* mServerIP;
	int mPort;

	NNCircularBuffer mRecvBuffer;
	NNCircularBuffer mSendBuffer;

	std::map<short,NNBaseHandler*> mPacketHandler;

private:
	static NNNetworkSystem* mpInstance;

	NNNetworkSystem();
	~NNNetworkSystem();
};