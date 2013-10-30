
#pragma once

#include "NNConfig.h"
#include <math.h>



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
	~NNPoint() {}

public:
	NNPoint& operator= ( const NNPoint& point );
	NNPoint operator+( const NNPoint& point ) const;
	NNPoint operator-( const NNPoint& point ) const;
	NNPoint operator-() const;
	NNPoint operator*( float n ) const;
	NNPoint operator/( float n ) const;

public:
	inline float GetDistance( NNPoint& point ) const { 
		return sqrtf( pow(m_X-point.GetX(), 2) + pow(m_Y-point.GetY(), 2) );
	}
	inline float GetDistance( float x, float y ) const { 
		return sqrtf( pow(m_X-x, 2) + pow(m_Y-y, 2) );
	}

public:
	inline float GetX() const { return m_X; }
	inline float GetY() const { return m_Y; }

	void SetPoint( float x, float y ) {
		m_X = x;
		m_Y = y;
	}
	void SetPoint( NNPoint& point ) { *this = point; }
	void SetX( float x ) { m_X = x; }
	void SetY( float y ) { m_Y = y; }
};


