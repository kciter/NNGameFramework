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