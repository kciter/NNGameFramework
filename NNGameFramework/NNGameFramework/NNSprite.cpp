
/**
 * NNSprite.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 07
 */

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
	switch ( rendererStatus )
	{
	case D2D:
		pInstance = new NND2DSprite( path );
		break;
	case D3D:
		pInstance = new NND3DSprite( path );
		break;
	default:
		break;
	}
	
	return pInstance;
} 
NNSprite* NNSprite::Create( NNZip *buf )
{
	static RendererStatus rendererStatus = NNApplication::GetInstance()->GetRendererStatus();

	NNSprite* pInstance = nullptr;
	switch ( rendererStatus )
	{
	case D2D:
		pInstance = new NND2DSprite( buf );
		break;
	case D3D:
		pInstance = new NND3DSprite( buf );
		break;
	default:
		break;
	}
	
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

	m_D2DMatrix._11 = m_Matrix._11; m_D2DMatrix._12 = m_Matrix._12;
	m_D2DMatrix._21 = m_Matrix._21; m_D2DMatrix._22 = m_Matrix._22;
	m_D2DMatrix._31 = m_Matrix._31; m_D2DMatrix._32 = m_Matrix._32;

	m_pD2DRenderer->GetHwndRenderTarget()->SetTransform( m_D2DMatrix );
	m_pD2DRenderer->GetHwndRenderTarget()->DrawBitmap( 
		m_pD2DTexture->GetD2DBitmap(), D2D1::RectF(0.f,0.f,m_ImageWidth,m_ImageHeight),
		m_Opacity );
}

//////////////////////////////////////////////////////////////////////////
/*					NND3DSprite											*/
//////////////////////////////////////////////////////////////////////////
NND3DSprite::NND3DSprite()
{
	D3DXMatrixIdentity( &m_D3DMatrix );
}
NND3DSprite::NND3DSprite( std::wstring path )
{
	D3DXMatrixIdentity( &m_D3DMatrix );
	mpD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD3DTexture = static_cast<NND3DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	D3DSURFACE_DESC desc;
	mpD3DTexture->GetTexture()->GetLevelDesc( 0, &desc );

	m_ImageWidth = (float)desc.Width;
	m_ImageHeight = (float)desc.Height;
}
NND3DSprite::NND3DSprite( NNZip* buf )
{
	D3DXMatrixIdentity( &m_D3DMatrix );
	mpD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD3DTexture = static_cast<NND3DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromMemory( buf ));

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

	m_D3DMatrix._11 = m_Matrix._11; m_D3DMatrix._12 = m_Matrix._12;
	m_D3DMatrix._21 = m_Matrix._21; m_D3DMatrix._22 = m_Matrix._22;
	m_D3DMatrix._41 = m_Matrix._31; m_D3DMatrix._42 = m_Matrix._32;

	mpD3DRenderer->GetSprite()->Begin( D3DXSPRITE_ALPHABLEND );
	mpD3DRenderer->GetSprite()->SetTransform( &m_D3DMatrix );
	mpD3DRenderer->GetSprite()->Draw( mpD3DTexture->GetTexture(), NULL, NULL, NULL, D3DCOLOR_ARGB(255,255,255,255) );
	mpD3DRenderer->GetSprite()->End();
}
