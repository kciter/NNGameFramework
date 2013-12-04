
/**
 * NNSpriteAtlas.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 05
 */

#include "NNSpriteAtlas.h"
#include "NNResourceManager.h"
#include "NNApplication.h"

//////////////////////////////////////////////////////////////////////////
/*					NNSpriteAtlas										*/
//////////////////////////////////////////////////////////////////////////
NNSpriteAtlas* NNSpriteAtlas::Create( std::wstring path )
{
	static RendererStatus rendererStatus = NNApplication::GetInstance()->GetRendererStatus();

	NNSpriteAtlas* pInstance = nullptr;
	switch ( rendererStatus )
	{
	case D2D:
		pInstance = new NND2DSpriteAtlas( path );
		break;
	case D3D:
		pInstance = new NND3DSpriteAtlas( path );
		break;
	default:
		break;
	}
	
	return pInstance;
}
NNSpriteAtlas* NNSpriteAtlas::Create( NNZip *buf )
{
	static RendererStatus rendererStatus = NNApplication::GetInstance()->GetRendererStatus();

	NNSpriteAtlas* pInstance = nullptr;
	/*switch ( rendererStatus )
	{
	case D2D:
	*/	pInstance = new NND2DSpriteAtlas( buf );
	/*	break;
	default:
		break;
	}*/
	
	return pInstance;
}

//////////////////////////////////////////////////////////////////////////
/*					NND2DSpriteAtlas									*/
//////////////////////////////////////////////////////////////////////////
NND2DSpriteAtlas::NND2DSpriteAtlas()
	: m_pD2DRenderer(nullptr), m_pD2DTexture(nullptr)
{

}
NND2DSpriteAtlas::NND2DSpriteAtlas( std::wstring path )
{
	m_pD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	m_pD2DTexture = static_cast<NND2DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	m_ImageWidth = m_pD2DTexture->GetD2DBitmap()->GetSize().width;
	m_ImageHeight = m_pD2DTexture->GetD2DBitmap()->GetSize().height;
}
NND2DSpriteAtlas::NND2DSpriteAtlas( NNZip *buf )
{
	m_pD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	m_pD2DTexture = static_cast<NND2DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromMemory( buf ));

	m_ImageWidth = m_pD2DTexture->GetD2DBitmap()->GetSize().width;
	m_ImageHeight = m_pD2DTexture->GetD2DBitmap()->GetSize().height;
}
NND2DSpriteAtlas::~NND2DSpriteAtlas()
{
	Destroy();
}
void NND2DSpriteAtlas::Destroy()
{
	m_pD2DRenderer = nullptr;
	m_pD2DTexture = nullptr;
}

void NND2DSpriteAtlas::Render()
{
	NNObject::Render();

	m_D2DMatrix._11 = m_Matrix._11; m_D2DMatrix._12 = m_Matrix._12;
	m_D2DMatrix._21 = m_Matrix._21; m_D2DMatrix._22 = m_Matrix._22;
	m_D2DMatrix._31 = m_Matrix._31; m_D2DMatrix._32 = m_Matrix._32;

	m_pD2DRenderer->GetHwndRenderTarget()->SetTransform( m_D2DMatrix );
	m_pD2DRenderer->GetHwndRenderTarget()->DrawBitmap( 
		//m_pD2DTexture->GetD2DBitmap(), D2D1::RectF(m_CutLeftX,m_CutTopY,m_CutRightX,m_CutBottomY),
		m_pD2DTexture->GetD2DBitmap(), D2D1::RectF(0,0,m_CutRightX-m_CutLeftX,m_CutBottomY-m_CutTopY),
		m_Opacity, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, D2D1::RectF(m_CutLeftX,m_CutTopY,m_CutRightX,m_CutBottomY) );
}

//////////////////////////////////////////////////////////////////////////
/*					NND3DSprite											*/
//////////////////////////////////////////////////////////////////////////
NND3DSpriteAtlas::NND3DSpriteAtlas()
{
	D3DXMatrixIdentity( &m_D3DMatrix );
}
NND3DSpriteAtlas::NND3DSpriteAtlas( std::wstring path )
{
	D3DXMatrixIdentity( &m_D3DMatrix );
	mpD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD3DTexture = static_cast<NND3DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	D3DSURFACE_DESC desc;
	mpD3DTexture->GetTexture()->GetLevelDesc( 0, &desc );

	m_ImageWidth = (float)desc.Width;
	m_ImageHeight = (float)desc.Height;
}
NND3DSpriteAtlas::~NND3DSpriteAtlas()
{
	Destroy();
}

void NND3DSpriteAtlas::Destroy()
{
	mpD3DRenderer = nullptr;
	mpD3DTexture = nullptr;
}
void NND3DSpriteAtlas::Render()
{
	NNObject::Render();

	m_D3DMatrix._11 = m_Matrix._11; m_D3DMatrix._12 = m_Matrix._12;
	m_D3DMatrix._21 = m_Matrix._21; m_D3DMatrix._22 = m_Matrix._22;
	m_D3DMatrix._41 = m_Matrix._31; m_D3DMatrix._42 = m_Matrix._32;

	m_Rect.left = (LONG)m_CutLeftX;
	m_Rect.top = (LONG)m_CutTopY;
	m_Rect.right = (LONG)m_CutRightX;
	m_Rect.bottom = (LONG)m_CutBottomY;

	mpD3DRenderer->GetSprite()->Begin( D3DXSPRITE_ALPHABLEND );
	mpD3DRenderer->GetSprite()->SetTransform( &m_D3DMatrix );
	mpD3DRenderer->GetSprite()->Draw( mpD3DTexture->GetTexture(), &m_Rect, NULL, NULL, D3DCOLOR_ARGB(255,255,255,255) );
	mpD3DRenderer->GetSprite()->End();
}
