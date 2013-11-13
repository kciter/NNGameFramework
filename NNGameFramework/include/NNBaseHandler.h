
#pragma once

#include "NNCircularBuffer.h"
#include "NNPacketHeader.h"

class NNBaseHandler
{
public:
	NNBaseHandler(){}
	virtual ~NNBaseHandler(){}

	virtual void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header ) = 0;
};