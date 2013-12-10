
/**
 * NNLabel.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 05
 */

#pragma once

#include "NNObject.h"
#include "NND2DRenderer.h"
#include "NND3DRenderer.h"

#include "NNColor.h"

/* */
/* NNLabel
/* 텍스트를 출력 할 수 있는 라벨 노드
/* */

class NNLabel : public NNObject
{
protected:
	wchar_t* mFontFace;
	wchar_t* mString;
	float mFontSize;
	NNColor mColor;
	bool mBold;
	bool mItalic;

public:
	NNLabel()
		: mFontFace(nullptr), mString(nullptr), mFontSize(0.f),
		  mBold(false), mItalic(false)
	{}
	virtual ~NNLabel(){}

	void Init(){}

	static NNLabel* Create( wchar_t* string, wchar_t* fontFace, float fontSize );
	virtual void Destroy() = 0;
	virtual void Render() = 0;

	inline wchar_t* GetString() const { return mString; }
	inline wchar_t* GetFontFace() const { return mFontFace; }
	inline float GetFontSize() const { return mFontSize; }
	inline NNColor GetColor() { return mColor; }
	inline bool IsItalic() const { return mItalic; }
	inline bool IsBold() const { return mBold; }

	void SetString( wchar_t* string ) { mString = string; }
	virtual void SetFontSize( float fontsize ) { mFontSize = fontsize; }
	virtual void SetFontFace( wchar_t* fontface ) { mFontFace = fontface; }
	virtual void SetBold( bool bold ) { mBold = bold; }
	virtual void SetItalic( bool italic ) { mItalic = italic; }
	virtual void SetColor( NNColor color ) { mColor = color; }
	virtual void SetRed( int r ) { mColor.SetRed(r); }
	virtual void SetGreen( int g ) { mColor.SetGreen(g); }
	virtual void SetBlue( int b ) { mColor.SetBlue(b); }
	virtual void SetColor( int r, int g, int b ) { mColor.SetRGB(r,g,b); }
	virtual void SetOpacity( float opacity ) { mColor.SetOpacity(opacity); }
	virtual void SetRGBA( int r, int g, int b, int a ) { mColor.SetRGBA(r,g,b,a); }
};

class NND2DLabel : public NNLabel
{
private:
	NND2DRenderer* mpD2DRenderer;

	IDWriteFactory* mDWriteFactory;
	IDWriteTextFormat* mTextFormat;
	ID2D1SolidColorBrush* mBrush;

public:
	NND2DLabel();
	NND2DLabel( wchar_t* string, wchar_t* face, float fontSize );
	virtual ~NND2DLabel();

	void Destroy();
	void Render();
private:
	void SetTextFormat();

public:
	void SetFontSize( float fontsize ) { mFontSize = fontsize; SetTextFormat(); }
	void SetFontFace( wchar_t* fontface ) { mFontFace = fontface; SetTextFormat();}
	void SetBold( bool bold ) { mBold = bold; SetTextFormat(); }
	void SetItalic( bool italic ) { mItalic = italic; SetTextFormat(); }
	void SetRed( int r) { NNLabel::SetRed(r); mBrush->SetColor(D2D1::ColorF(r/255.f,mColor.GetGreen()/255.f,mColor.GetBlue()/255.f)); }
	void SetGreen( int g ) {NNLabel::SetGreen(g); mBrush->SetColor(D2D1::ColorF(mColor.GetRed()/255.f,g/255.f,mColor.GetBlue()/255.f)); }
	void SetBlue( int b ) { NNLabel::SetBlue(b); mBrush->SetColor(D2D1::ColorF(mColor.GetRed()/255.f,mColor.GetGreen()/255.f,b/255.f)); }
	void SetColor( int r, int g, int b )
	{
		NNLabel::SetColor(r,g,b);
		mBrush->SetColor(D2D1::ColorF(r/255.f,g/255.f,b/255.f));
	}
	void SetOpacity( float opacity ) { NNLabel::SetOpacity(opacity); mBrush->SetOpacity(opacity); }
	void SetRGBA( int r, int g, int b, int a )
	{
		NNLabel::SetRGBA(r,g,b,a);
		mBrush->SetColor(D2D1::ColorF(r/255.f,g/255.f,b/255.f));
		mBrush->SetOpacity(a/255.f);
	}

private:
	D2D1::Matrix3x2F mD2DMatrix;
};

class NND3DLabel : public NNLabel
{
private:
	NND3DRenderer* mpD3DRenderer;

public:
	NND3DLabel();
	NND3DLabel( wchar_t* string, wchar_t* face, float fontSize );
	virtual ~NND3DLabel();

	void Destroy();
	void Render();

private:
	RECT mRect;
	LPD3DXFONT mD3DFont;
	D3DXMATRIX mD3DMatrix;
};