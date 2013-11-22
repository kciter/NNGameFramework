
#pragma once

#include "NNConfig.h"

/* */
/* NNSize
/* �簢���� ������� ��ǥ�� ����ִ� Ŭ����
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
	inline float GetWidth() const { return m_Width; }
	/* �簢���� �ʺ� */
	inline float GetHeight() const { return m_Height; }
	/* �簢���� ���� */

	void SetWidth( float width ) { m_Width = width; }
	/* �簢���� �ʺ� �����ϴ� �Լ� */
	void SetHeight( float height) { m_Height = height; }
	/* �簢���� ���̸� �����ϴ� �Լ� */
	void SetSize( float width, float height ) {
		m_Width = width;
		m_Height = height;
	}
	/* �簢���� ũ�⸦ �����ϴ� �Լ� */
	void SetSize( NNSize& size ) { *this = size; }
	/* �簢���� ũ�⸦ �����ϴ� �Լ� */
};


