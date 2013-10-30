
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
{
	NND2DLabel();

	m_String = string;
	m_FontFace = fontFace;
	m_FontSize = fontSize;

	m_pD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	DWriteCreateFactory( DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(m_DWriteFactory),
		reinterpret_cast<IUnknown**>(&m_DWriteFactory) );

	SetTextFormat();

	m_pD2DRenderer->GetHwndRenderTarget()->CreateSolidColorBrush( D2D1::ColorF(m_ColorR,m_ColorG,m_ColorB), &m_Brush );
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
	m_pD2DRenderer->GetHwndRenderTarget()->SetTransform( m_Matrix );
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


