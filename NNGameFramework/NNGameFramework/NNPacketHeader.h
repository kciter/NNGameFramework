
/**
 * NNPacketHeader
 * 작성자: 이선협
 * 작성일: 2013. 11. 12
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
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