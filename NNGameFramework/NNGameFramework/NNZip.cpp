
/**
 * NNZip.cpp
 * �ۼ���: ����ȯ
 * �ۼ���: 2013. 11. 27
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
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