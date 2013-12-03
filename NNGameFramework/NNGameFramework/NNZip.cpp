
/**
 * NNZip.cpp
 * 작성자: 김지환
 * 작성일: 2013. 11. 27
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNZip.h"
#include <string>
#include "NNMacroSet.h"

NNZip::NNZip(char *buf, int size)
{
	m_size = size;
	m_buf = new char[size];
	memcpy(m_buf, buf, size);
}
NNZip::~NNZip(void)
{
	SafeDelete(m_buf);
}
NNZip* NNZip::Create(char *buf, int size)
{
	NNZip* pInstacne = new NNZip(buf, size);

	return pInstacne;
}