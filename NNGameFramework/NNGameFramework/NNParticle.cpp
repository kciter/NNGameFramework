
/**
 * NNParticle.cpp
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNParticle.h"
#include "NNApplication.h"
#include "NNResourceManager.h"
#include "NNConfig.h"

//////////////////////////////////////////////////////////////////////////
/*					NNParticle											*/
//////////////////////////////////////////////////////////////////////////

NNParticle* NNParticle::Create( std::wstring path )
{
	static RendererStatus rendererStatus = NNApplication::GetInstance()->GetRendererStatus();

	NNParticle* pInstance = nullptr;
	switch ( rendererStatus )
	{
	case D2D:
		pInstance = new NND2DParticle( path );
		break;
	case D3D:
		pInstance = new NND3DParticle( path );
		break;
	default:
		break;
	}
	
	return pInstance;
}

void NNParticle::Render()
{
	mMatrix = NNMatrix::Translate( -mImageWidth/2.f, -mImageHeight/2.f ) *
		NNMatrix::Rotation( mRotation ) *
		NNMatrix::Scale( mScaleX, mScaleY ) *
		NNMatrix::Translate( mPosition.GetX(), mPosition.GetY() );

	mMatrix = mMatrix * mParentMatrix;
}
void NNParticle::Update( float dTime )
{
	mNowLifeTime += dTime;

	mSpeed = mStartSpeed + (mEndSpeed-mStartSpeed)*(mNowLifeTime/mLifeTime);
	mRotationSpeed = mStartRotationSpeed + (mEndRotationSpeed-mStartRotationSpeed)*(mNowLifeTime/mLifeTime);

	mPosition = mPosition + NNPoint( cos(NNDegreeToRadian(mDirection)), sin(NNDegreeToRadian(mDirection)) ) * mSpeed * dTime;
	mRotation += mRotationSpeed * dTime;

	mScaleX = (mStartScaleX + (mEndScaleX-mStartScaleX)*(mNowLifeTime/mLifeTime));
	mScaleY = (mStartScaleY + (mEndScaleY-mStartScaleY)*(mNowLifeTime/mLifeTime));
	mColor = (mStartColor + (mEndColor-mStartColor)*(mNowLifeTime/mLifeTime));
}


//////////////////////////////////////////////////////////////////////////
/*					NND2DParticle										*/
//////////////////////////////////////////////////////////////////////////
NND2DParticle::NND2DParticle()
	: mpD2DRenderer(nullptr), mpD2DTexture(nullptr)
{

}
NND2DParticle::NND2DParticle( std::wstring path )
{
	mpD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD2DTexture = static_cast<NND2DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	mImageWidth = mpD2DTexture->GetD2DBitmap()->GetSize().width;
	mImageHeight = mpD2DTexture->GetD2DBitmap()->GetSize().height;
}
NND2DParticle::~NND2DParticle()
{
	Destroy();
}
void NND2DParticle::Destroy()
{
	mpD2DRenderer = nullptr;
	mpD2DTexture = nullptr;
}

void NND2DParticle::Render()
{
	NNParticle::Render();

// 	블랜딩 모드 추가해야함

	mD2DMatrix._11 = mMatrix._11; mD2DMatrix._12 = mMatrix._12;
	mD2DMatrix._21 = mMatrix._21; mD2DMatrix._22 = mMatrix._22;
	mD2DMatrix._31 = mMatrix._31; mD2DMatrix._32 = mMatrix._32;

	mpD2DRenderer->GetHwndRenderTarget()->SetTransform( mD2DMatrix );
	mpD2DRenderer->GetHwndRenderTarget()->DrawBitmap(
		mpD2DTexture->GetD2DBitmap(), D2D1::RectF(0.f,0.f,mImageWidth,mImageHeight),
		mColor.GetOpacity() );
}

void NND2DParticle::Update( float dTime )
{
	NNParticle::Update( dTime );
}

//////////////////////////////////////////////////////////////////////////
/*					NND3DParticle										*/
//////////////////////////////////////////////////////////////////////////
NND3DParticle::NND3DParticle()
	: mpD3DRenderer(nullptr), mpD3DTexture(nullptr)
{
	D3DXMatrixIdentity( &mD3DMatrix );
}
NND3DParticle::NND3DParticle( std::wstring path )
	: mpD3DRenderer(nullptr), mpD3DTexture(nullptr)
{
	mpD3DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	mpD3DTexture = static_cast<NND3DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	D3DSURFACE_DESC desc;
	mpD3DTexture->GetTexture()->GetLevelDesc( 0, &desc );

	mImageWidth = (float)desc.Width;
	mImageHeight = (float)desc.Height;

	D3DXMatrixIdentity( &mD3DMatrix );
}
NND3DParticle::~NND3DParticle()
{
	Destroy();
}

void NND3DParticle::Destroy()
{
	mpD3DRenderer = nullptr;
	mpD3DTexture = nullptr;
}

void NND3DParticle::Render()
{
	NNParticle::Render();

	mD3DMatrix._11 = mMatrix._11; mD3DMatrix._12 = mMatrix._12;
	mD3DMatrix._21 = mMatrix._21; mD3DMatrix._22 = mMatrix._22;
	mD3DMatrix._41 = mMatrix._31; mD3DMatrix._42 = mMatrix._32;

	mpD3DRenderer->GetSprite()->Begin( D3DXSPRITE_ALPHABLEND );
	mpD3DRenderer->GetSprite()->SetTransform( &mD3DMatrix );

	mpD3DRenderer->GetDevice()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	mpD3DRenderer->GetDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE );
	mpD3DRenderer->GetDevice()->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD );

	mpD3DRenderer->GetSprite()->Draw( mpD3DTexture->GetTexture(), NULL, NULL, NULL, D3DCOLOR_ARGB(mColor.GetAlpha(),mColor.GetRed(),mColor.GetGreen(),mColor.GetBlue()) );
	mpD3DRenderer->GetSprite()->End();
}
void NND3DParticle::Update( float dTime )
{
	NNParticle::Update( dTime );
}