
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
	: mpD2DRenderer(nullptr), mDWriteFactory(nullptr),
	  mTextFormat(nullptr), mBrush(nullptr)
{
}
NND2DLabel::NND2DLabel( wchar_t* string, wchar_t* fontFace, float fontSize )
	: mpD2DRenderer(nullptr), mDWriteFactory(nullptr),
	  mTextFormat(nullptr), mBrush(nullptr)
{
	mColor = NNColor(0,0,0,1.f);

	mString = string;
	mFontFace = fontFace;
	mFontSize = fontSize;

	mpD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	DWriteCreateFactory( DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(mDWriteFactory),
		reinterpret_cast<IUnknown**>(&mDWriteFactory) );

	SetTextFormat();

	mpD2DRenderer->GetHwndRenderTarget()->CreateSolidColorBrush( D2D1::ColorF(mColor.GetRed()/255.f,mColor.GetGreen()/255.f,mColor.GetBlue()/255.f), &mBrush );
}
NND2DLabel::~NND2DLabel()
{
	Destroy();
}

void NND2DLabel::Destroy()
{
	SafeRelease( mDWriteFactory );
	SafeRelease( mTextFormat );
}

void NND2DLabel::Render()
{
	NNObject::Render();

	mD2DMatrix._11 = mMatrix._11; mD2DMatrix._12 = mMatrix._12;
	mD2DMatrix._21 = mMatrix._21; mD2DMatrix._22 = mMatrix._22;
	mD2DMatrix._31 = mMatrix._31; mD2DMatrix._32 = mMatrix._32;

	mpD2DRenderer->GetHwndRenderTarget()->SetTransform( mD2DMatrix );
	mpD2DRenderer->GetHwndRenderTarget()->DrawTextW( mString,
		wcslen(mString), 
		mTextFormat, 
		D2D1::RectF(0,0,mpD2DRenderer->GetHwndRenderTarget()->GetSize().width,mpD2DRenderer->GetHwndRenderTarget()->GetSize().height),
		mBrush );
}
void NND2DLabel::SetTextFormat()
{
	SafeRelease( mTextFormat );
	mDWriteFactory->CreateTextFormat( mFontFace, NULL,
		mBold ? DWRITE_FONT_WEIGHT_BOLD : DWRITE_FONT_WEIGHT_NORMAL,
		mItalic ? DWRITE_FONT_STYLE_ITALIC : DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL, mFontSize, L"ko", &mTextFormat );
}


NND3DLabel::NND3DLabel()
	: mpD3DRenderer(nullptr), mD3DFont(nullptr)
{
	D3DXMatrixIdentity( &mD3DMatrix );
}
NND3DLabel::NND3DLabel( wchar_t* string, wchar_t* face, float fontSize )
	: mpD3DRenderer(nullptr), mD3DFont(nullptr)
{
	mpD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());

	D3DXMatrixIdentity( &mD3DMatrix );

	mColor = NNColor(0,0,0,1.f);

	mString = string;
	mFontFace = face;
	mFontSize = fontSize;

	mRect.left = mRect.top = 0;
	mRect.right = mRect.bottom = -1;

	D3DXCreateFont( mpD3DRenderer->GetDevice(), int(mFontSize), int(mFontSize/2.2f), FW_NORMAL, D3DX_DEFAULT,
		false, DEFAULT_CHARSET, OUT_TT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, mFontFace, &mD3DFont );
}
NND3DLabel::~NND3DLabel()
{
	Destroy();
}

void NND3DLabel::Destroy()
{
	SafeRelease( mD3DFont );
	mpD3DRenderer = nullptr;
}
void NND3DLabel::Render()
{
	NNObject::Render();

	mD3DMatrix._11 = mMatrix._11; mD3DMatrix._12 = mMatrix._12;
	mD3DMatrix._21 = mMatrix._21; mD3DMatrix._22 = mMatrix._22;
	mD3DMatrix._41 = mMatrix._31; mD3DMatrix._42 = mMatrix._32;

	mpD3DRenderer->GetSprite()->Begin( D3DXSPRITE_ALPHABLEND );
	mpD3DRenderer->GetSprite()->SetTransform( &mD3DMatrix );
	mD3DFont->DrawTextW( mpD3DRenderer->GetSprite(), mString, -1, &mRect, DT_TOP | DT_LEFT | DT_NOCLIP | DT_WORDBREAK, D3DCOLOR_ARGB(mColor.GetAlpha(),mColor.GetRed(),mColor.GetGreen(),mColor.GetBlue()) );
	mpD3DRenderer->GetSprite()->End();
}