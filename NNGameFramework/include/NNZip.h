
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

	static NNZip *Create(char *buf, int size);

	char *GetBuffer() { return mbuf; }
	int GetSize() { return msize; }

private:
	char *mbuf;
	int msize;
};

