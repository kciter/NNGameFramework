
/**
 * NNSpriteAtlas.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 07
 */

#pragma once

#include "NNObject.h"
#include "NNConfig.h"
#include "NNZip.h"
#include "NNTexture.h"
#include "NND2DRenderer.h"
#include "NND3DRenderer.h"

class NNSpriteAtlas : public NNObject
{
public:
	NNSpriteAtlas()
		: mImageWidth(0.f), mImageHeight(0.f),
		mColorR(0.f), mColorG(0.f), mColorB(0.f), mOpacity(1.f){}
	virtual ~NNSpriteAtlas(){}

	void Init(){}

	void Render(){}
	void Update( float dTime ){}

	static NNSpriteAtlas* Create( std::wstring path );
	static NNSpriteAtlas* Create( NNZip *buf );

	inline float GetImageWidth() const { return mImageWidth; }
	inline float GetImageHeight() const { return mImageHeight; }
	inline float GetOpacity() const { return mOpacity; }

	void SetImageWidth( float width ) { mImageWidth = width; }
	void SetImageHeight( float height ) { mImageHeight = height; }
	void SetOpacity( float opacity ) { mOpacity = opacity; }
	void SetCutSize( float leftX, float topY, float rightX, float bottomY ) { mCutLeftX=leftX; mCutTopY=topY; mCutRightX=rightX; mCutBottomY=bottomY; }

protected:
	float mImageWidth;
	float mImageHeight;
	float mColorR, mColorG, mColorB;
	float mOpacity;
	float mCutLeftX, mCutTopY, mCutRightX, mCutBottomY;
};

class NND2DSpriteAtlas : public NNSpriteAtlas
{
private:
	NND2DRenderer* mpD2DRenderer;
	NND2DTexture* mpD2DTexture;

public:
	NND2DSpriteAtlas();
	NND2DSpriteAtlas( std::wstring path );
	NND2DSpriteAtlas( NNZip *buf );
	virtual ~NND2DSpriteAtlas();

	void Destroy();
	void Render();

private:
	D2D1::Matrix3x2F mD2DMatrix;
};

class NND3DSpriteAtlas : public NNSpriteAtlas
{
private:
	NND3DRenderer* mpD3DRenderer;
	NND3DTexture* mpD3DTexture;

public:
	NND3DSpriteAtlas();
	NND3DSpriteAtlas( std::wstring path );
	NND3DSpriteAtlas( NNZip* buf );
	virtual ~NND3DSpriteAtlas();

	void Destroy();
	void Render();

private:
	D3DXMATRIX mD3DMatrix;
	RECT mRect;
};