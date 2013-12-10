
/**
 * NNSize.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNConfig.h"

/* */
/* NNSize
/* 사각형의 사이즈와 좌표를 담고있는 클래스
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
	/* 생성자 */
	~NNSize() {}
	/* 소멸자 */

public:
	NNSize& operator= ( const NNSize& size );
	NNSize operator+( const NNSize& size ) const;
	NNSize operator-( const NNSize& size ) const;
	NNSize operator-() const;
	NNSize operator*( float n ) const;
	NNSize operator/( float n ) const;
	/* 연산자 오버로딩 */

public:
	inline float GetWidth() const { return mWidth; }
	/* 사각형의 너비 */
	inline float GetHeight() const { return mHeight; }
	/* 사각형의 높이 */

	void SetWidth( float width ) { mWidth = width; }
	/* 사각형의 너비를 설정하는 함수 */
	void SetHeight( float height) { mHeight = height; }
	/* 사각형의 높이를 설정하는 함수 */
	void SetSize( float width, float height ) {
		mWidth = width;
		mHeight = height;
	}
	/* 사각형의 크기를 설정하는 함수 */
	void SetSize( NNSize& size ) { *this = size; }
	/* 사각형의 크기를 설정하는 함수 */
};


