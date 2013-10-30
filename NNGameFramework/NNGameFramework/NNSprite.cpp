
#include "NNSprite.h"
#include "NNResourceManager.h"
#include "NNApplication.h"

//////////////////////////////////////////////////////////////////////////
/*					NNSprite											*/
//////////////////////////////////////////////////////////////////////////
NNSprite* NNSprite::Create( std::wstring path )
{
	static RendererStatus rendererStatus = NNApplication::GetInstance()->GetRendererStatus();

	NNSprite* pInstance = nullptr;
	/*switch ( rendererStatus )
	{
	case D2D:
	*/	pInstance = new NND2DSprite( path );
	/*	break;
	default:
		break;
	}*/
	
	return pInstance;
}

//////////////////////////////////////////////////////////////////////////
/*					NND2DSprite											*/
//////////////////////////////////////////////////////////////////////////
NND2DSprite::NND2DSprite()
	: m_pD2DRenderer(nullptr), m_pD2DTexture(nullptr)
{

}
NND2DSprite::NND2DSprite( std::wstring path )
{
	m_pD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	m_pD2DTexture = static_cast<NND2DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	m_ImageWidth = m_pD2DTexture->GetD2DBitmap()->GetSize().width;
	m_ImageHeight = m_pD2DTexture->GetD2DBitmap()->GetSize().height;
}
NND2DSprite::~NND2DSprite()
{
	Destroy();
}
void NND2DSprite::Destroy()
{
	m_pD2DRenderer = nullptr;
	m_pD2DTexture = nullptr;
}

void NND2DSprite::Render()
{
	NNObject::Render();

	m_pD2DRenderer->GetHwndRenderTarget()->SetTransform( m_Matrix );
	m_pD2DRenderer->GetHwndRenderTarget()->DrawBitmap( 
		m_pD2DTexture->GetD2DBitmap(), D2D1::RectF(0.f,0.f,m_ImageWidth,m_ImageHeight),
		m_Opacity );
}

