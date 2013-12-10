
/**
 * NNColor.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 20
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

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
		: mRed(255), mGreen(255), mBlue(255), mOpacity(1.f) {}
	NNColor( int r, int g, int b, int a ) 
		: mRed(r), mGreen(g), mBlue(b), mOpacity(static_cast<float>(a/255.f)) {}
	NNColor( int r, int g, int b, float opacity ) 
		: mRed(r), mGreen(g), mBlue(b), mOpacity(opacity) {}
	NNColor( NNColor& color )
		: mRed(color.GetRed()), mGreen(color.GetGreen()), mBlue(color.GetBlue()), mOpacity(color.GetOpacity()) {}
	/* ������ */
	~NNColor() {}
	/* �Ҹ��� */

	void SetRGB( int r, int g, int b )
	{
		mRed = r;
		mGreen = g;
		mBlue = b;
	}
	/* RGB�� ���� */
	void SetRGBA( int r, int g, int b, int a )
	{
		mRed = r;
		mGreen = g;
		mBlue = b;
		mOpacity = static_cast<float>(a/255.f);
	}
	/* RGB, Alpha�� ���� */
	void SetRed( int r ) { mRed = r; }
	/* RGB�� �� R�� ���� ���� */
	void SetGreen( int g ) { mGreen = g; }
	/* RGB�� �� G�� ���� ���� */
	void SetBlue( int b ) { mBlue = b; }
	/* RGB�� �� B�� ���� ���� */
	void SetOpacity( float opacity ) { mOpacity = opacity; }
	/* ���� �� ���� */
	void SetAlpha( int a ) { mOpacity = static_cast<float>(a/255.f); }
	/* Alpha�� ���� */

	int GetRed() const { return mRed; }
	/* RGB�� �� R�� �� ��ȯ */
	int GetGreen() const { return mGreen; }
	/* RGB�� �� G�� �� ��ȯ */
	int GetBlue() const { return mBlue; }
	/* RGB�� �� B�� �� ��ȯ */
	float GetOpacity() const { return mOpacity; }
	/* ���� �� ��ȯ */
	int GetAlpha() const { return static_cast<int>(mOpacity*255); }
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
	int mRed;
	int mGreen;
	int mBlue;
	float mOpacity;
};