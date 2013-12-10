
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

public:
	char *GetBuffer() { return mbuf; }
	int GetSize() { return msize; }

private:
	static NNZip *Create(char *buf, int size);

private:
	char *mbuf;
	int msize;

	friend class NNResourceManager;
};

