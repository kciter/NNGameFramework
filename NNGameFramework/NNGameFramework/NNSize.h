
/**
 * NNSize.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#pragma once

#include "NNConfig.h"

/* */
/* NNSize
/* �簢���� ������� ��ǥ�� ����ִ� Ŭ����
/* */

class NNSize
{
private:
	float mWidth;
	float mHeight;

public:
	NNSize() 
		: mWidth(0.f), mHeight(0.f) {}
	NNSize( float width, float height )
		: mWidth(width), mHeight(height) {}
	NNSize( NNSize& size )
		: mWidth(size.GetWidth()), mHeight(size.GetHeight()) {}
	/* ������ */
	~NNSize() {}
	/* �Ҹ��� */

public:
	NNSize& operator= ( const NNSize& size );
	NNSize operator+( const NNSize& size ) const;
	NNSize operator-( const NNSize& size ) const;
	NNSize operator-() const;
	NNSize operator*( float n ) const;
	NNSize operator/( float n ) const;
	/* ������ �����ε� */

public:
	inline float GetWidth() const { return mWidth; }
	/* �簢���� �ʺ� */
	inline float GetHeight() const { return mHeight; }
	/* �簢���� ���� */

	void SetWidth( float width ) { mWidth = width; }
	/* �簢���� �ʺ� �����ϴ� �Լ� */
	void SetHeight( float height) { mHeight = height; }
	/* �簢���� ���̸� �����ϴ� �Լ� */
	void SetSize( float width, float height ) {
		mWidth = width;
		mHeight = height;
	}
	/* �簢���� ũ�⸦ �����ϴ� �Լ� */
	void SetSize( NNSize& size ) { *this = size; }
	/* �簢���� ũ�⸦ �����ϴ� �Լ� */
};


