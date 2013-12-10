
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
	: mpD2DRenderer(nullptr), mpD2DTexture(nullptr)
{

}
NND2DSprite::NND2DSprite( std::wstring path )
{
	mpD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD2DTexture = static_cast<NND2DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	mImageWidth = mpD2DTexture->GetD2DBitmap()->GetSize().width;
	mImageHeight = mpD2DTexture->GetD2DBitmap()->GetSize().height;
}
NND2DSprite::NND2DSprite( NNZip *buf )
{
	mpD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD2DTexture = static_cast<NND2DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromMemory( buf ));

	mImageWidth = mpD2DTexture->GetD2DBitmap()->GetSize().width;
	mImageHeight = mpD2DTexture->GetD2DBitmap()->GetSize().height;
}
NND2DSprite::~NND2DSprite()
{
	Destroy();
}
void NND2DSprite::Destroy()
{
	mpD2DRenderer = nullptr;
	mpD2DTexture = nullptr;
}

void NND2DSprite::Render()
{
	NNObject::Render();

	mD2DMatrix._11 = mMatrix._11; mD2DMatrix._12 = mMatrix._12;
	mD2DMatrix._21 = mMatrix._21; mD2DMatrix._22 = mMatrix._22;
	mD2DMatrix._31 = mMatrix._31; mD2DMatrix._32 = mMatrix._32;

	mpD2DRenderer->GetHwndRenderTarget()->SetTransform( mD2DMatrix );
	mpD2DRenderer->GetHwndRenderTarget()->DrawBitmap( 
		mpD2DTexture->GetD2DBitmap(), D2D1::RectF(0.f,0.f,mImageWidth,mImageHeight),
		mOpacity );
}

//////////////////////////////////////////////////////////////////////////
/*					NND3DSprite											*/
//////////////////////////////////////////////////////////////////////////
NND3DSprite::NND3DSprite()
{
	D3DXMatrixIdentity( &mD3DMatrix );
}
NND3DSprite::NND3DSprite( std::wstring path )
{
	D3DXMatrixIdentity( &mD3DMatrix );
	mpD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD3DTexture = static_cast<NND3DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	D3DSURFACE_DESC desc;
	mpD3DTexture->GetTexture()->GetLevelDesc( 0, &desc );

	mImageWidth = (float)desc.Width;
	mImageHeight = (float)desc.Height;
}
NND3DSprite::NND3DSprite( NNZip* buf )
{
	D3DXMatrixIdentity( &mD3DMatrix );
	mpD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD3DTexture = static_cast<NND3DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromMemory( buf ));

	D3DSURFACE_DESC desc;
	mpD3DTexture->GetTexture()->GetLevelDesc( 0, &desc );

	mImageWidth = (float)desc.Width;
	mImageHeight = (float)desc.Height;
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

	mD3DMatrix._11 = mMatrix._11; mD3DMatrix._12 = mMatrix._12;
	mD3DMatrix._21 = mMatrix._21; mD3DMatrix._22 = mMatrix._22;
	mD3DMatrix._41 = mMatrix._31; mD3DMatrix._42 = mMatrix._32;

	mpD3DRenderer->GetSprite()->Begin( D3DXSPRITE_ALPHABLEND );
	mpD3DRenderer->GetSprite()->SetTransform( &mD3DMatrix );
	mpD3DRenderer->GetSprite()->Draw( mpD3DTexture->GetTexture(), NULL, NULL, NULL, D3DCOLOR_ARGB(255,255,255,255) );
	mpD3DRenderer->GetSprite()->End();
}
