
#pragma once

/* */
/* NNColor
/* 컬러 정보를 담고있는 클래스
/* RGB값과 투명도 정보를 담고있다.
/* 투명도를 Alpha값으로 변환할 수 있다.
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
	/* 생성자 */
	~NNColor() {}
	/* 소멸자 */

	void SetRGB( int r, int g, int b )
	{
		m_Red = r;
		m_Green = g;
		m_Blue = b;
	}
	/* RGB값 설정 */
	void SetRGBA( int r, int g, int b, int a )
	{
		m_Red = r;
		m_Green = g;
		m_Blue = b;
		m_Opacity = static_cast<float>(a/255.f);
	}
	/* RGB, Alpha값 설정 */
	void SetRed( int r ) { m_Red = r; }
	/* RGB값 중 R의 값만 설정 */
	void SetGreen( int g ) { m_Green = g; }
	/* RGB값 중 G의 값만 설정 */
	void SetBlue( int b ) { m_Blue = b; }
	/* RGB값 중 B의 값만 설정 */
	void SetOpacity( float opacity ) { m_Opacity = opacity; }
	/* 투명도 값 설정 */
	void SetAlpha( int a ) { m_Opacity = static_cast<float>(a/255.f); }
	/* Alpha값 설정 */

	int GetRed() const { return m_Red; }
	/* RGB값 중 R의 값 반환 */
	int GetGreen() const { return m_Green; }
	/* RGB값 중 G의 값 반환 */
	int GetBlue() const { return m_Blue; }
	/* RGB값 중 B의 값 반환 */
	float GetOpacity() const { return m_Opacity; }
	/* 투명도 값 반환 */
	int GetAlpha() const { return static_cast<int>(m_Opacity*255); }
	/* Alpha값 반환 */

public:
	NNColor& operator= ( const NNColor& color );
	NNColor operator+( const NNColor& color ) const;
	NNColor operator-( const NNColor& color ) const;
	NNColor operator-() const;
	NNColor operator*( float n ) const;
	NNColor operator/( float n ) const;
	/* 연산자 오버로딩 */

private:
	int m_Red;
	int m_Green;
	int m_Blue;
	float m_Opacity;
};