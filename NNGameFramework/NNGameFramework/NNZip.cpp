#include "NNZip.h"


NNZip::NNZip(char *buf, int size)
{
	m_buf = buf;
	m_size = size;
}
NNZip::~NNZip(void)
{
}
NNZip* NNZip::Create(char *buf, int size)
{
	NNZip* pInstacne = new NNZip(buf, size);
	return pInstacne;
}