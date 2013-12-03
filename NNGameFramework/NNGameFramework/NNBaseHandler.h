
/**
 * NNBaseHandler
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 13
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
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