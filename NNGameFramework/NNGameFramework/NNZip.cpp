
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
	msize = size;
	mbuf = new char[size];
	memcpy(mbuf, buf, size);
}
NNZip::~NNZip(void)
{
	SafeDelete(mbuf);
}
NNZip* NNZip::Create(char *buf, int size)
{
	NNZip* pInstacne = new NNZip(buf, size);

	return pInstacne;
}