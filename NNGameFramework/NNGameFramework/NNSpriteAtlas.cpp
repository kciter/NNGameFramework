
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
	/*switch ( rendererStatus )
	{
	case D2D:
	*/	pInstance = new NND2DSpriteAtlas( path );
	/*	break;
	default:
		break;
	}*/
	
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

	m_pD2DRenderer->GetHwndRenderTarget()->SetTransform( m_Matrix );
	m_pD2DRenderer->GetHwndRenderTarget()->DrawBitmap( 
		//m_pD2DTexture->GetD2DBitmap(), D2D1::RectF(m_CutLeftX,m_CutTopY,m_CutRightX,m_CutBottomY),
		m_pD2DTexture->GetD2DBitmap(), D2D1::RectF(0,0,m_CutRightX-m_CutLeftX,m_CutBottomY-m_CutTopY),
		m_Opacity, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, D2D1::RectF(m_CutLeftX,m_CutTopY,m_CutRightX,m_CutBottomY) );
}

