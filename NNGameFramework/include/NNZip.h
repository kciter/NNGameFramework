
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

	char *GetBuffer() { return m_buf; }
	int GetSize() { return m_size; }

private:
	char *m_buf;
	int m_size;
};

