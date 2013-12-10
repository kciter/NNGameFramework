
/**
 * NNZip.h
 * 작성자: 김지환
 * 작성일: 2013. 11. 27
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
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

