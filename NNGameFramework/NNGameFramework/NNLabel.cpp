
/**
 * NNLabel.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 05
 */

#include "NNLabel.h"
#include "NNApplication.h"

//////////////////////////////////////////////////////////////////////////
/*					NNLabel												*/
//////////////////////////////////////////////////////////////////////////
NNLabel* NNLabel::Create( wchar_t* string, wchar_t* fontFace, float fontSize )
{
	static RendererStatus rendererStatus = NNApplication::GetInstance()->GetRendererStatus();

	NNLabel* pInstance = nullptr;

	switch ( rendererStatus )
	{
	case D2D:
		pInstance = new NND2DLabel( string, fontFace, fontSize );
		break;
	case D3D:
		pInstance = new NND3DLabel( string, fontFace, fontSize );
		break;
	default:
		break;
	}

	return pInstance;
}

//////////////////////////////////////////////////////////////////////////
/*					NND2DLabel											*/
//////////////////////////////////////////////////////////////////////////
NND2DLabel::NND2DLabel()
	: m_pD2DRenderer(nullptr), m_DWriteFactory(nullptr),
	  m_TextFormat(nullptr), m_Brush(nullptr)
{
}
NND2DLabel::NND2DLabel( wchar_t* string, wchar_t* fontFace, float fontSize )
	: m_pD2DRenderer(nullptr), m_DWriteFactory(nullptr),
	  m_TextFormat(nullptr), m_Brush(nullptr)
{
	m_Color = NNColor(0,0,0,1.f);

	m_String = string;
	m_FontFace = fontFace;
	m_FontSize = fontSize;

	m_pD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	DWriteCreateFactory( DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(m_DWriteFactory),
		reinterpret_cast<IUnknown**>(&m_DWriteFactory) );

	SetTextFormat();

	m_pD2DRenderer->GetHwndRenderTarget()->CreateSolidColorBrush( D2D1::ColorF(m_Color.GetRed()/255.f,m_Color.GetGreen()/255.f,m_Color.GetBlue()/255.f), &m_Brush );
}
NND2DLabel::~NND2DLabel()
{
	Destroy();
}

void NND2DLabel::Destroy()
{
	SafeRelease( m_DWriteFactory );
	SafeRelease( m_TextFormat );
}

void NND2DLabel::Render()
{
	NNObject::Render();

	m_D2DMatrix._11 = m_Matrix._11; m_D2DMatrix._12 = m_Matrix._12;
	m_D2DMatrix._21 = m_Matrix._21; m_D2DMatrix._22 = m_Matrix._22;
	m_D2DMatrix._31 = m_Matrix._31; m_D2DMatrix._32 = m_Matrix._32;

	m_pD2DRenderer->GetHwndRenderTarget()->SetTransform( m_D2DMatrix );
	m_pD2DRenderer->GetHwndRenderTarget()->DrawTextW( m_String,
		wcslen(m_String), 
		m_TextFormat, 
		D2D1::RectF(0,0,m_pD2DRenderer->GetHwndRenderTarget()->GetSize().width,m_pD2DRenderer->GetHwndRenderTarget()->GetSize().height),
		m_Brush );
}
void NND2DLabel::SetTextFormat()
{
	SafeRelease( m_TextFormat );
	m_DWriteFactory->CreateTextFormat( m_FontFace, NULL,
		m_Bold ? DWRITE_FONT_WEIGHT_BOLD : DWRITE_FONT_WEIGHT_NORMAL,
		m_Italic ? DWRITE_FONT_STYLE_ITALIC : DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL, m_FontSize, L"ko", &m_TextFormat );
}


NND3DLabel::NND3DLabel()
	: m_pD3DRenderer(nullptr), m_D3DFont(nullptr)
{
	D3DXMatrixIdentity( &m_D3DMatrix );
}
NND3DLabel::NND3DLabel( wchar_t* string, wchar_t* face, float fontSize )
	: m_pD3DRenderer(nullptr), m_D3DFont(nullptr)
{
	m_pD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());

	D3DXMatrixIdentity( &m_D3DMatrix );

	m_Color = NNColor(0,0,0,1.f);

	m_String = string;
	m_FontFace = face;
	m_FontSize = fontSize;

	m_Rect.left = m_Rect.top = 0;
	m_Rect.right = m_Rect.bottom = -1;

	D3DXCreateFont( m_pD3DRenderer->GetDevice(), int(m_FontSize), int(m_FontSize/2.2f), FW_NORMAL, D3DX_DEFAULT,
		false, DEFAULT_CHARSET, OUT_TT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, m_FontFace, &m_D3DFont );
}
NND3DLabel::~NND3DLabel()
{
	Destroy();
}

void NND3DLabel::Destroy()
{
	SafeRelease( m_D3DFont );
	m_pD3DRenderer = nullptr;
}
void NND3DLabel::Render()
{
	NNObject::Render();

	m_D3DMatrix._11 = m_Matrix._11; m_D3DMatrix._12 = m_Matrix._12;
	m_D3DMatrix._21 = m_Matrix._21; m_D3DMatrix._22 = m_Matrix._22;
	m_D3DMatrix._41 = m_Matrix._31; m_D3DMatrix._42 = m_Matrix._32;

	m_pD3DRenderer->GetSprite()->Begin( D3DXSPRITE_ALPHABLEND );
	m_pD3DRenderer->GetSprite()->SetTransform( &m_D3DMatrix );
	m_D3DFont->DrawTextW( m_pD3DRenderer->GetSprite(), m_String, -1, &m_Rect, DT_TOP | DT_LEFT | DT_NOCLIP | DT_WORDBREAK, D3DCOLOR_ARGB(m_Color.GetAlpha(),m_Color.GetRed(),m_Color.GetGreen(),m_Color.GetBlue()) );
	m_pD3DRenderer->GetSprite()->End();
}