
/**
 * NNPacketHeader
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 12
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#pragma once

#pragma pack(push, 1)

struct NNPacketHeader
{
	NNPacketHeader() : mSize(0), mType(0) {}
	short mSize;
	short mType;
};

#pragma pack(pop)