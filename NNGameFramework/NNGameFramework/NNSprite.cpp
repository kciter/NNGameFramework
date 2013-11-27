
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
NNSprite* NNSprite::Create( NNZip *buf )
{
	static RendererStatus rendererStatus = NNApplication::GetInstance()->GetRendererStatus();

	NNSprite* pInstance = nullptr;
	/*switch ( rendererStatus )
	{
	case D2D:
	*/	pInstance = new NND2DSprite( buf );
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
NND2DSprite::NND2DSprite( NNZip *buf )
{
	m_pD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	m_pD2DTexture = static_cast<NND2DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromMemory( buf ));

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

//////////////////////////////////////////////////////////////////////////
/*					NND3DSprite											*/
//////////////////////////////////////////////////////////////////////////
NND3DSprite::NND3DSprite()
{

}
NND3DSprite::NND3DSprite( std::wstring path )
{
	mpD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD3DTexture = static_cast<NND3DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	D3DSURFACE_DESC desc;
	mpD3DTexture->GetTexture()->GetLevelDesc( 0, &desc );

	m_ImageWidth = (float)desc.Width;
	m_ImageHeight = (float)desc.Height;
}
NND3DSprite::~NND3DSprite()
{
	Destroy();
}

void NND3DSprite::Destroy()
{
	mpD3DRenderer = nullptr;
	mpD3DTexture = nullptr;
}
void NND3DSprite::Render()
{
	NNObject::Render();

	mpD3DRenderer->GetSprite()->Begin( D3DXSPRITE_ALPHABLEND );
//	mpD3DRenderer->GetSprite()->SetTransform( &m_Matrix );
	mpD3DRenderer->GetSprite()->Draw( mpD3DTexture->GetTexture(), NULL, NULL, NULL, D3DCOLOR_ARGB(255,255,255,255) );
	mpD3DRenderer->GetSprite()->End();
}
