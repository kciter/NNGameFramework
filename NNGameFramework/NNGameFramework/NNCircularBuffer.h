
/**
 * NNCircularBuffer.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 12
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#pragma once

class NNCircularBuffer
{
public:
	friend class NNNetworkSystem;

	NNCircularBuffer(size_t capacity) ;
	~NNCircularBuffer() ;

public:
	size_t GetCurrentSize() const
	{ 
		return mCurrentSize ; 
	}

	size_t GetCapacity() const
	{ 
		return mCapacity ;
	}

	bool Write(const char* data, size_t bytes) ;

	bool Read(char* data, size_t bytes) ;

	/// ������ ���ĺ��� (�������� �ʰ�)
	void Peek(char* data) ;
	bool Peek(char* data, size_t bytes) ;

	/// ������ ����
	bool Consume(size_t bytes) ;

private:
	size_t mBeginIndex ;
	size_t mEndIndex ;
	size_t mCurrentSize ;
	size_t mCapacity ;

	char* mData ;
};
