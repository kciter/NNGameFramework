
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
	wchar_t* m_FontFace;
	wchar_t* m_String;
	float m_FontSize;
	NNColor m_Color;
	bool m_Bold;
	bool m_Italic;

public:
	NNLabel()
		: m_FontFace(nullptr), m_String(nullptr), m_FontSize(0.f),
		  m_Bold(false), m_Italic(false)
	{}
	virtual ~NNLabel(){}

	void Init(){}

	static NNLabel* Create( wchar_t* string, wchar_t* fontFace, float fontSize );
	virtual void Destroy() = 0;
	virtual void Render() = 0;

	inline wchar_t* GetString() const { return m_String; }
	inline wchar_t* GetFontFace() const { return m_FontFace; }
	inline float GetFontSize() const { return m_FontSize; }
	inline NNColor GetColor() { return m_Color; }
	inline bool IsItalic() const { return m_Italic; }
	inline bool IsBold() const { return m_Bold; }

	void SetString( wchar_t* string ) { m_String = string; }
	virtual void SetFontSize( float fontsize ) { m_FontSize = fontsize; }
	virtual void SetFontFace( wchar_t* fontface ) { m_FontFace = fontface; }
	virtual void SetBold( bool bold ) { m_Bold = bold; }
	virtual void SetItalic( bool italic ) { m_Italic = italic; }
	virtual void SetColor( NNColor color ) { m_Color = color; }
	virtual void SetRed( int r ) { m_Color.SetRed(r); }
	virtual void SetGreen( int g ) { m_Color.SetGreen(g); }
	virtual void SetBlue( int b ) { m_Color.SetBlue(b); }
	virtual void SetColor( int r, int g, int b ) { m_Color.SetRGB(r,g,b); }
	virtual void SetOpacity( float opacity ) { m_Color.SetOpacity(opacity); }
	virtual void SetRGBA( int r, int g, int b, int a ) { m_Color.SetRGBA(r,g,b,a); }
};

class NND2DLabel : public NNLabel
{
private:
	NND2DRenderer* m_pD2DRenderer;

	IDWriteFactory* m_DWriteFactory;
	IDWriteTextFormat* m_TextFormat;
	ID2D1SolidColorBrush* m_Brush;

public:
	NND2DLabel();
	NND2DLabel( wchar_t* string, wchar_t* face, float fontSize );
	virtual ~NND2DLabel();

	void Destroy();
	void Render();
private:
	void SetTextFormat();

public:
	void SetFontSize( float fontsize ) { m_FontSize = fontsize; SetTextFormat(); }
	void SetFontFace( wchar_t* fontface ) { m_FontFace = fontface; SetTextFormat();}
	void SetBold( bool bold ) { m_Bold = bold; SetTextFormat(); }
	void SetItalic( bool italic ) { m_Italic = italic; SetTextFormat(); }
	void SetRed( int r) { NNLabel::SetRed(r); m_Brush->SetColor(D2D1::ColorF(r/255.f,m_Color.GetGreen()/255.f,m_Color.GetBlue()/255.f)); }
	void SetGreen( int g ) {NNLabel::SetGreen(g); m_Brush->SetColor(D2D1::ColorF(m_Color.GetRed()/255.f,g/255.f,m_Color.GetBlue()/255.f)); }
	void SetBlue( int b ) { NNLabel::SetBlue(b); m_Brush->SetColor(D2D1::ColorF(m_Color.GetRed()/255.f,m_Color.GetGreen()/255.f,b/255.f)); }
	void SetColor( int r, int g, int b )
	{
		NNLabel::SetColor(r,g,b);
		m_Brush->SetColor(D2D1::ColorF(r/255.f,g/255.f,b/255.f));
	}
	void SetOpacity( float opacity ) { NNLabel::SetOpacity(opacity); m_Brush->SetOpacity(opacity); }
	void SetRGBA( int r, int g, int b, int a )
	{
		NNLabel::SetRGBA(r,g,b,a);
		m_Brush->SetColor(D2D1::ColorF(r/255.f,g/255.f,b/255.f));
		m_Brush->SetOpacity(a/255.f);
	}

private:
	D2D1::Matrix3x2F m_D2DMatrix;
};

class NND3DLabel : public NNLabel
{
private:
	NND3DRenderer* m_pD3DRenderer;

public:
	NND3DLabel();
	NND3DLabel( wchar_t* string, wchar_t* face, float fontSize );
	virtual ~NND3DLabel();

	void Destroy();
	void Render();

private:
	RECT m_Rect;
	LPD3DXFONT m_D3DFont;
	D3DXMATRIX m_D3DMatrix;
};