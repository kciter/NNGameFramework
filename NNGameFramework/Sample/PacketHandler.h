
#pragma once

#include "NNBaseHandler.h"
#include "NNCircularBuffer.h"
#include "PacketType.h"

class LoginHandler : public NNBaseHandler
{
public:
	LoginHandler();
	virtual ~LoginHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	LoginRequest m_LoginRequestPacket;
	LoginResult m_LoginResultPacket;
	LoginBroadcastRequest m_LoginBroadcastRequestPacket;
	LoginBroadcastResult m_LoginBroadcastResultPacket;

	bool m_LoginCheck;
	bool m_NewLoginCheck;
};

class MoveBroadcastHandler : public NNBaseHandler
{
public:
	MoveBroadcastHandler();
	virtual ~MoveBroadcastHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	MoveBroadcastRequest m_MoveBroadcastRequestPacket;
	MoveBroadcastResult m_MoveBroadcastResultPacket;
};