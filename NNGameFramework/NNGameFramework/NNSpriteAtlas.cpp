
/**
 * NNSpriteAtlas.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 07
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
	: mpD2DRenderer(nullptr), mpD2DTexture(nullptr)
{

}
NND2DSpriteAtlas::NND2DSpriteAtlas( std::wstring path )
{
	mpD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD2DTexture = static_cast<NND2DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	mImageWidth = mpD2DTexture->GetD2DBitmap()->GetSize().width;
	mImageHeight = mpD2DTexture->GetD2DBitmap()->GetSize().height;
}
NND2DSpriteAtlas::NND2DSpriteAtlas( NNZip *buf )
{
	mpD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD2DTexture = static_cast<NND2DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromMemory( buf ));

	mImageWidth = mpD2DTexture->GetD2DBitmap()->GetSize().width;
	mImageHeight = mpD2DTexture->GetD2DBitmap()->GetSize().height;
}
NND2DSpriteAtlas::~NND2DSpriteAtlas()
{
	Destroy();
}
void NND2DSpriteAtlas::Destroy()
{
	mpD2DRenderer = nullptr;
	mpD2DTexture = nullptr;
}

void NND2DSpriteAtlas::Render()
{
	NNObject::Render();

	mD2DMatrix._11 = mMatrix._11; mD2DMatrix._12 = mMatrix._12;
	mD2DMatrix._21 = mMatrix._21; mD2DMatrix._22 = mMatrix._22;
	mD2DMatrix._31 = mMatrix._31; mD2DMatrix._32 = mMatrix._32;

	mpD2DRenderer->GetHwndRenderTarget()->SetTransform( mD2DMatrix );
	mpD2DRenderer->GetHwndRenderTarget()->DrawBitmap( 
		//mpD2DTexture->GetD2DBitmap(), D2D1::RectF(mCutLeftX,mCutTopY,mCutRightX,mCutBottomY),
		mpD2DTexture->GetD2DBitmap(), D2D1::RectF(0,0,mSize.GetWidth()-mSize.GetX(),mSize.GetHeight()-mSize.GetY()),
		mOpacity, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, D2D1::RectF(mSize.GetX(),mSize.GetY(),mSize.GetWidth(),mSize.GetHeight()) );
}

//////////////////////////////////////////////////////////////////////////
/*					NND3DSprite											*/
//////////////////////////////////////////////////////////////////////////
NND3DSpriteAtlas::NND3DSpriteAtlas()
{
	D3DXMatrixIdentity( &mD3DMatrix );
}
NND3DSpriteAtlas::NND3DSpriteAtlas( std::wstring path )
{
	D3DXMatrixIdentity( &mD3DMatrix );
	mpD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD3DTexture = static_cast<NND3DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	D3DSURFACE_DESC desc;
	mpD3DTexture->GetTexture()->GetLevelDesc( 0, &desc );

	mImageWidth = (float)desc.Width;
	mImageHeight = (float)desc.Height;
}
NND3DSpriteAtlas::NND3DSpriteAtlas( NNZip* buf )
{
	D3DXMatrixIdentity( &mD3DMatrix );
	mpD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD3DTexture = static_cast<NND3DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromMemory( buf ));

	D3DSURFACE_DESC desc;
	mpD3DTexture->GetTexture()->GetLevelDesc( 0, &desc );

	mImageWidth = (float)desc.Width;
	mImageHeight = (float)desc.Height;
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

	mD3DMatrix._11 = mMatrix._11; mD3DMatrix._12 = mMatrix._12;
	mD3DMatrix._21 = mMatrix._21; mD3DMatrix._22 = mMatrix._22;
	mD3DMatrix._41 = mMatrix._31; mD3DMatrix._42 = mMatrix._32;

	mRect.left = (LONG)mSize.GetX();
	mRect.top = (LONG)mSize.GetY();
	mRect.right = (LONG)mSize.GetWidth();
	mRect.bottom = (LONG)mSize.GetHeight();

	mpD3DRenderer->GetSprite()->Begin( D3DXSPRITE_ALPHABLEND );
	mpD3DRenderer->GetSprite()->SetTransform( &mD3DMatrix );
	mpD3DRenderer->GetSprite()->Draw( mpD3DTexture->GetTexture(), &mRect, NULL, NULL, D3DCOLOR_ARGB(255,255,255,255) );
	mpD3DRenderer->GetSprite()->End();
}
