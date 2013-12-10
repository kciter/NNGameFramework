
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
	float mX;
	float mY;
	float mWidth;
	float mHeight;

public:
	NNSize() 
		: mX(0.f), mY(0.f), mWidth(0.f), mHeight(0.f) {}
	NNSize( float x, float y, float width, float height )
		: mX(x), mY(y), mWidth(width), mHeight(height) {}
	NNSize( NNSize& size )
		: mX(size.GetX()), mY(size.GetY()), mWidth(size.GetWidth()), mHeight(size.GetHeight()) {}
	/* ������ */
	~NNSize() {}
	/* �Ҹ��� */

public:
	NNSize& operator= ( const NNSize& size );
	NNSize operator-() const;
	/* ������ �����ε� */

public:
	inline float GetX() const { return mX; }
	inline float GetY() const { return mY; }
	inline float GetWidth() const { return mWidth; }
	/* �簢���� �ʺ� */
	inline float GetHeight() const { return mHeight; }
	/* �簢���� ���� */

	void SetX( float x ) { mX = x; }
	void SetY( float y ) { mY = y; }
	void SetWidth( float width ) { mWidth = width; }
	/* �簢���� �ʺ� �����ϴ� �Լ� */
	void SetHeight( float height) { mHeight = height; }
	/* �簢���� ���̸� �����ϴ� �Լ� */
	void SetSize( float x, float y, float width, float height ) {
		mX = x;
		mY = y;
		mWidth = width;
		mHeight = height;
	}
	/* �簢���� ũ�⸦ �����ϴ� �Լ� */
	void SetSize( NNSize& size ) { *this = size; }
	/* �簢���� ũ�⸦ �����ϴ� �Լ� */
};