
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
	float m_X;
	float m_Y;

public:
	NNPoint() 
		: m_X(0.f), m_Y(0.f) {}
	NNPoint( float x, float y ) 
		: m_X(x), m_Y(y) {}
	NNPoint( NNPoint& point )
		: m_X(point.GetX()), m_Y(point.GetY()) {}
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
		return sqrtf( pow(m_X-point.GetX(), 2) + pow(m_Y-point.GetY(), 2) );
	}
	/* ���� �������� �Ÿ��� ����ϴ� �Լ� */
	inline float GetDistance( float x, float y ) const { 
		return sqrtf( pow(m_X-x, 2) + pow(m_Y-y, 2) );
	}
	/* ���� �������� �Ÿ��� ����ϴ� �Լ� */

public:
	inline float GetX() const { return m_X; }
	/* X��ǥ�� ��ȯ�ϴ� �Լ� */
	inline float GetY() const { return m_Y; }
	/* Y��ǥ�� ��ȯ�ϴ� �Լ� */

	void SetPoint( float x, float y ) {
		m_X = x;
		m_Y = y;
	}
	/* ��ǥ�� �����ϴ� �Լ� */
	void SetPoint( NNPoint& point ) { *this = point; }
	/* ��ǥ�� �����ϴ� �Լ� */
	void SetX( float x ) { m_X = x; }
	/* X��ǥ�� �����ϴ� �Լ� */
	void SetY( float y ) { m_Y = y; }
	/* Y��ǥ�� �����ϴ� �Լ� */
};


