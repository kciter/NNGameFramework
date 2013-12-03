
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

	char *GetBuffer() { return m_buf; }
	int GetSize() { return m_size; }

private:
	char *m_buf;
	int m_size;
};

