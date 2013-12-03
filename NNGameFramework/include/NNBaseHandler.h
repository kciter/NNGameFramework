
/**
 * NNBaseHandler
 * 작성자: 이선협
 * 작성일: 2013. 11. 13
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

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