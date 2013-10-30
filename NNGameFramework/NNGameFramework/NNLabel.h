
#pragma once

#include "NNObject.h"
#include "NND2DRenderer.h"

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
	float m_ColorR, m_ColorG, m_ColorB;
	float m_Opacity;
	bool m_Bold;
	bool m_Italic;

public:
	NNLabel()
		: m_FontFace(nullptr), m_String(nullptr), m_FontSize(0.f),
		  m_ColorR(0.f), m_ColorG(0.f), m_ColorB(0.f), m_Opacity(1.f),
		  m_Bold(false), m_Italic(false)
	{}
	virtual ~NNLabel(){}

	static NNLabel* Create( wchar_t* string, wchar_t* fontFace, float fontSize );
	virtual void Destroy() = 0;
	virtual void Render() = 0;

	inline wchar_t* GetString() const { return m_String; }
	inline wchar_t* GetFontFace() const { return m_FontFace; }
	inline float GetFontSize() const { return m_FontSize; }
	inline float GetRed() const { return m_ColorR; }
	inline float GetGreen() const { return m_ColorG; }
	inline float GetBlue() const { return m_ColorB; }
	inline float GetOpacity() const { return m_Opacity; }
	inline bool IsItalic() const { return m_Italic; }
	inline bool IsBold() const { return m_Bold; }

	void SetString( wchar_t* string ) { m_String = string; }
	virtual void SetFontSize( float fontsize ) { m_FontSize = fontsize; }
	virtual void SetFontFace( wchar_t* fontface ) { m_FontFace = fontface; }
	virtual void SetBold( bool bold ) { m_Bold = bold; }
	virtual void SetItalic( bool italic ) { m_Italic = italic; }
	virtual void SetRed( float r ) { m_ColorR = r; }
	virtual void SetGreen( float g ) { m_ColorG = g; }
	virtual void SetBlue( float b ) { m_ColorB = b; }
	virtual void SetColor( float r, float g, float b ) { m_ColorR = r; m_ColorG = g; m_ColorB = b; }
	virtual void SetOpacity( float opacity ) { m_Opacity = opacity; }
	virtual void SetRGBA( float r, float g, float b, float a ) { m_ColorR = r; m_ColorG = g; m_ColorB = b; m_Opacity = a; }
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
	void SetRed( float r) { m_ColorR = r; m_Brush->SetColor(D2D1::ColorF(r/255.f,m_ColorG/255.f,m_ColorB/255.f)); }
	void SetGreen( float g ) { m_ColorG = g; m_Brush->SetColor(D2D1::ColorF(m_ColorR/255.f,g/255.f,m_ColorB/255.f)); }
	void SetBlue( float b ) { m_ColorB = b; m_Brush->SetColor(D2D1::ColorF(m_ColorR/255.f,m_ColorG/255.f,b/255.f)); }
	void SetColor( float r, float g, float b )
	{
		m_ColorR = r; m_ColorG = g; m_ColorB = b;
		m_Brush->SetColor(D2D1::ColorF(r/255.f,g/255.f,b/255.f));
	}
	void SetOpacity( float opacity ) { m_Opacity = opacity; m_Brush->SetOpacity(opacity); }
	void SetRGBA( float r, float g, float b, float a )
	{
		m_ColorR = r; m_ColorG = g; m_ColorB = b;
		m_Opacity = a;
		m_Brush->SetColor(D2D1::ColorF(r/255.f,g/255.f,b/255.f));
		m_Brush->SetOpacity(a);
	}
};


