
#pragma once

class NNBaseHandler
{
public:
	NNBaseHandler();
	virtual ~NNBaseHandler();

	virtual void HandlerPacket( short packetType ) = 0;
};