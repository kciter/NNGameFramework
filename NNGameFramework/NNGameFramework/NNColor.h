
#pragma once

/* */
/* NNColor
/* �÷� ������ ����ִ� Ŭ����
/* RGB���� ���� ������ ����ִ�.
/* ������ Alpha������ ��ȯ�� �� �ִ�.
/* */

class NNColor
{
public:
	NNColor()
		: m_Red(255), m_Green(255), m_Blue(255), m_Opacity(1.f) {}
	NNColor( int r, int g, int b, int a ) 
		: m_Red(r), m_Green(g), m_Blue(b), m_Opacity(static_cast<float>(a/255.f)) {}
	NNColor( int r, int g, int b, float opacity ) 
		: m_Red(r), m_Green(g), m_Blue(b), m_Opacity(opacity) {}
	NNColor( NNColor& color )
		: m_Red(color.GetRed()), m_Green(color.GetGreen()), m_Blue(color.GetBlue()), m_Opacity(color.GetOpacity()) {}
	/* ������ */
	~NNColor() {}
	/* �Ҹ��� */

	void SetRGB( int r, int g, int b )
	{
		m_Red = r;
		m_Green = g;
		m_Blue = b;
	}
	/* RGB�� ���� */
	void SetRGBA( int r, int g, int b, int a )
	{
		m_Red = r;
		m_Green = g;
		m_Blue = b;
		m_Opacity = static_cast<float>(a/255.f);
	}
	/* RGB, Alpha�� ���� */
	void SetRed( int r ) { m_Red = r; }
	/* RGB�� �� R�� ���� ���� */
	void SetGreen( int g ) { m_Green = g; }
	/* RGB�� �� G�� ���� ���� */
	void SetBlue( int b ) { m_Blue = b; }
	/* RGB�� �� B�� ���� ���� */
	void SetOpacity( float opacity ) { m_Opacity = opacity; }
	/* ���� �� ���� */
	void SetAlpha( int a ) { m_Opacity = static_cast<float>(a/255.f); }
	/* Alpha�� ���� */

	int GetRed() const { return m_Red; }
	/* RGB�� �� R�� �� ��ȯ */
	int GetGreen() const { return m_Green; }
	/* RGB�� �� G�� �� ��ȯ */
	int GetBlue() const { return m_Blue; }
	/* RGB�� �� B�� �� ��ȯ */
	float GetOpacity() const { return m_Opacity; }
	/* ���� �� ��ȯ */
	int GetAlpha() const { return static_cast<int>(m_Opacity*255); }
	/* Alpha�� ��ȯ */

public:
	NNColor& operator= ( const NNColor& color );
	NNColor operator+( const NNColor& color ) const;
	NNColor operator-( const NNColor& color ) const;
	NNColor operator-() const;
	NNColor operator*( float n ) const;
	NNColor operator/( float n ) const;
	/* ������ �����ε� */

private:
	int m_Red;
	int m_Green;
	int m_Blue;
	float m_Opacity;
};