
#pragma once

#include "NNConfig.h"

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

public:
	NNSize& operator= ( const NNSize& size );
	NNSize operator+( const NNSize& size ) const;
	NNSize operator-( const NNSize& size ) const;
	NNSize operator-() const;
	NNSize operator*( float n ) const;
	NNSize operator/( float n ) const;

public:
	inline float GetWidth() const { return m_Width; }
	inline float GetHeight() const { return m_Height; }

	void SetWidth( float width ) { m_Width = width; }
	void SetHeight( float height) { m_Height = height; }
	void SetSize( float width, float height ) {
		m_Width = width;
		m_Height = height;
	}
	void SetSize( NNSize& size ) { *this = size; }
};


