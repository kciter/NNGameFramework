
/**
 * NNColor.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 20
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

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
		: mRed(255), mGreen(255), mBlue(255), mOpacity(1.f) {}
	NNColor( int r, int g, int b, int a ) 
		: mRed(r), mGreen(g), mBlue(b), mOpacity(static_cast<float>(a/255.f)) {}
	NNColor( int r, int g, int b, float opacity ) 
		: mRed(r), mGreen(g), mBlue(b), mOpacity(opacity) {}
	NNColor( NNColor& color )
		: mRed(color.GetRed()), mGreen(color.GetGreen()), mBlue(color.GetBlue()), mOpacity(color.GetOpacity()) {}
	/* 생성자 */
	~NNColor() {}
	/* 소멸자 */

	void SetRGB( int r, int g, int b )
	{
		mRed = r;
		mGreen = g;
		mBlue = b;
	}
	/* RGB값 설정 */
	void SetRGBA( int r, int g, int b, int a )
	{
		mRed = r;
		mGreen = g;
		mBlue = b;
		mOpacity = static_cast<float>(a/255.f);
	}
	/* RGB, Alpha값 설정 */
	void SetRed( int r ) { mRed = r; }
	/* RGB값 중 R의 값만 설정 */
	void SetGreen( int g ) { mGreen = g; }
	/* RGB값 중 G의 값만 설정 */
	void SetBlue( int b ) { mBlue = b; }
	/* RGB값 중 B의 값만 설정 */
	void SetOpacity( float opacity ) { mOpacity = opacity; }
	/* 투명도 값 설정 */
	void SetAlpha( int a ) { mOpacity = static_cast<float>(a/255.f); }
	/* Alpha값 설정 */

	int GetRed() const { return mRed; }
	/* RGB값 중 R의 값 반환 */
	int GetGreen() const { return mGreen; }
	/* RGB값 중 G의 값 반환 */
	int GetBlue() const { return mBlue; }
	/* RGB값 중 B의 값 반환 */
	float GetOpacity() const { return mOpacity; }
	/* 투명도 값 반환 */
	int GetAlpha() const { return static_cast<int>(mOpacity*255); }
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
	int mRed;
	int mGreen;
	int mBlue;
	float mOpacity;
};