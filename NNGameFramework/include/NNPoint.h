
/**
 * NNPoint.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

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
	float mX;
	float mY;

public:
	NNPoint() 
		: mX(0.f), mY(0.f) {}
	NNPoint( float x, float y ) 
		: mX(x), mY(y) {}
	NNPoint( NNPoint& point )
		: mX(point.GetX()), mY(point.GetY()) {}
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
		return sqrtf( pow(mX-point.GetX(), 2) + pow(mY-point.GetY(), 2) );
	}
	/* 점과 점사이의 거리를 계산하는 함수 */
	inline float GetDistance( float x, float y ) const { 
		return sqrtf( pow(mX-x, 2) + pow(mY-y, 2) );
	}
	/* 점과 점사이의 거리를 계산하는 함수 */

public:
	inline float GetX() const { return mX; }
	/* X좌표를 반환하는 함수 */
	inline float GetY() const { return mY; }
	/* Y좌표를 반환하는 함수 */

	void SetPoint( float x, float y ) {
		mX = x;
		mY = y;
	}
	/* 좌표를 설정하는 함수 */
	void SetPoint( NNPoint& point ) { *this = point; }
	/* 좌표를 설정하는 함수 */
	void SetX( float x ) { mX = x; }
	/* X좌표를 설정하는 함수 */
	void SetY( float y ) { mY = y; }
	/* Y좌표를 설정하는 함수 */
};


