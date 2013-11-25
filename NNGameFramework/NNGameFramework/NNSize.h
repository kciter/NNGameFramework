
#pragma once

#include "NNConfig.h"

/* */
/* NNSize
/* 사각형의 사이즈와 좌표를 담고있는 클래스
/* */

class NNSize
{
private:
	float m_Width;
	float m_Height;

public:
	NNSize() 
		: m_Width(0.f), m_Height(0.f) {}
	NNSize( float width, float height )
		: m_Width(width), m_Height(height) {}
	NNSize( NNSize& size )
		: m_Width(size.GetWidth()), m_Height(size.GetHeight()) {}
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
	inline float GetWidth() const { return m_Width; }
	/* 사각형의 너비 */
	inline float GetHeight() const { return m_Height; }
	/* 사각형의 높이 */

	void SetWidth( float width ) { m_Width = width; }
	/* 사각형의 너비를 설정하는 함수 */
	void SetHeight( float height) { m_Height = height; }
	/* 사각형의 높이를 설정하는 함수 */
	void SetSize( float width, float height ) {
		m_Width = width;
		m_Height = height;
	}
	/* 사각형의 크기를 설정하는 함수 */
	void SetSize( NNSize& size ) { *this = size; }
	/* 사각형의 크기를 설정하는 함수 */
};


