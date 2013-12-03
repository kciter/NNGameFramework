
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
	NNPacketHeader() : m_Size(0), m_Type(0) {}
	short m_Size;
	short m_Type;
};

#pragma pack(pop)