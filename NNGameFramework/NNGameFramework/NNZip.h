
/**
 * NNZip.h
 * �ۼ���: ����ȯ
 * �ۼ���: 2013. 11. 27
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#pragma once

class NNZip
{
public:
	NNZip(char *buf, int size);
	~NNZip(void);

	static NNZip *Create(char *buf, int size);

	char *GetBuffer() { return mbuf; }
	int GetSize() { return msize; }

private:
	char *mbuf;
	int msize;
};

