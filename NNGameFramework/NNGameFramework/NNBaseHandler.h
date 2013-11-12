
#pragma once

class NNBaseHandler
{
public:
	NNBaseHandler();
	virtual ~NNBaseHandler();

	virtual void HandlingPacket( short packetType ) = 0;
};