
#pragma once

#include "NNConfig.h"
#include <math.h>

/* */
/* NNPoint
/* 한 점의 좌표를 나타내는 클래스
/* */

class NNPoint
{
private:
	float m_X;
	float m_Y;

public:
	NNPoint() 
		: m_X(0.f), m_Y(0.f) {}
	NNPoint( float x, float y ) 
		: m_X(x), m_Y(y) {}
	NNPoint( NNPoint& point )
		: m_X(point.GetX()), m_Y(point.GetY()) {}
	/* 생성자 */
	~NNPoint() {}
	/* 소멸자 */

public:
	NNPoint& operator= ( const NNPoint& point );
	NNPoint operator+( const NNPoint& point ) const;
	NNPoint operator-( const NNPoint& point ) const;
	NNPoint operator-() const;
	NNPoint operator*( float n ) const;
	NNPoint operator/( float n ) const;
	/* 연산자 오버로딩 */

public:
	NNPoint NNPoint::Lerp( const NNPoint& startPoint, const NNPoint& endPoint, float t )
	{
		return NNPoint( t * startPoint.GetX() + ( 1 - t ) * endPoint.GetX()
			, t * startPoint.GetY() + ( 1 - t ) * endPoint.GetY() );
	}

public:
	inline float GetDistance( NNPoint& point ) const { 
		return sqrtf( pow(m_X-point.GetX(), 2) + pow(m_Y-point.GetY(), 2) );
	}
	/* 점과 점사이의 거리를 계산하는 함수 */
	inline float GetDistance( float x, float y ) const { 
		return sqrtf( pow(m_X-x, 2) + pow(m_Y-y, 2) );
	}
	/* 점과 점사이의 거리를 계산하는 함수 */

public:
	inline float GetX() const { return m_X; }
	/* X좌표를 반환하는 함수 */
	inline float GetY() const { return m_Y; }
	/* Y좌표를 반환하는 함수 */

	void SetPoint( float x, float y ) {
		m_X = x;
		m_Y = y;
	}
	/* 좌표를 설정하는 함수 */
	void SetPoint( NNPoint& point ) { *this = point; }
	/* 좌표를 설정하는 함수 */
	void SetX( float x ) { m_X = x; }
	/* X좌표를 설정하는 함수 */
	void SetY( float y ) { m_Y = y; }
	/* Y좌표를 설정하는 함수 */
};


