
/**
 * NNPoint.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#pragma once

#include "NNConfig.h"
#include <math.h>

/* */
/* NNPoint
/* �� ���� ��ǥ�� ��Ÿ���� Ŭ����
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
	/* ������ */
	~NNPoint() {}
	/* �Ҹ��� */

public:
	NNPoint& operator= ( const NNPoint& point );
	NNPoint operator+( const NNPoint& point ) const;
	NNPoint operator-( const NNPoint& point ) const;
	NNPoint operator-() const;
	NNPoint operator*( float n ) const;
	NNPoint operator/( float n ) const;
	/* ������ �����ε� */

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
	/* ���� �������� �Ÿ��� ����ϴ� �Լ� */
	inline float GetDistance( float x, float y ) const { 
		return sqrtf( pow(mX-x, 2) + pow(mY-y, 2) );
	}
	/* ���� �������� �Ÿ��� ����ϴ� �Լ� */

public:
	inline float GetX() const { return mX; }
	/* X��ǥ�� ��ȯ�ϴ� �Լ� */
	inline float GetY() const { return mY; }
	/* Y��ǥ�� ��ȯ�ϴ� �Լ� */

	void SetPoint( float x, float y ) {
		mX = x;
		mY = y;
	}
	/* ��ǥ�� �����ϴ� �Լ� */
	void SetPoint( NNPoint& point ) { *this = point; }
	/* ��ǥ�� �����ϴ� �Լ� */
	void SetX( float x ) { mX = x; }
	/* X��ǥ�� �����ϴ� �Լ� */
	void SetY( float y ) { mY = y; }
	/* Y��ǥ�� �����ϴ� �Լ� */
};


