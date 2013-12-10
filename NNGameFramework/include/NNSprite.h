
/**
 * NNSprite.h
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

/* */
/* NNSprite
/* 텍스쳐를 출력 할 수 있는 스프라이트 노드
/* */

class NNSprite : public NNObject
{
protected:
	float mImageWidth;
	float mImageHeight;
	float mColorR, mColorG, mColorB;
	float mOpacity;
public:
	NNSprite()
		: mImageWidth(0.f), mImageHeight(0.f),
		  mColorR(0.f), mColorG(0.f), mColorB(0.f), mOpacity(1.f)
	{}
	virtual ~NNSprite(){}

public:
	void Init(){}
	//static NNSprite* Create();
	static NNSprite* Create( std::wstring path );
	static NNSprite* Create( NNZip *buf );
	virtual void Destroy() {}
	virtual void Render() {}

public:
	inline float GetImageWidth() const { return mImageWidth; }
	inline float GetImageHeight() const { return mImageHeight; }
	inline float GetOpacity() const { return mOpacity; }

	void SetImageWidth( float width ) { mImageWidth = width; }
	void SetImageHeight( float height ) { mImageHeight = height; }
	void SetOpacity( float opacity ) { mOpacity = opacity; }
};

class NND2DSprite : public NNSprite
{
private:
	NND2DRenderer* mpD2DRenderer;
	NND2DTexture* mpD2DTexture;

public:
	NND2DSprite();
	NND2DSprite( std::wstring path );
	NND2DSprite( NNZip *buf );
	virtual ~NND2DSprite();

	void Destroy();
	void Render();

private:
	D2D1::Matrix3x2F mD2DMatrix;
};

class NND3DSprite : public NNSprite
{
private:
	NND3DRenderer* mpD3DRenderer;
	NND3DTexture* mpD3DTexture;

public:
	NND3DSprite();
	NND3DSprite( std::wstring path );
	NND3DSprite( NNZip* buf );
	virtual ~NND3DSprite();

	void Destroy();
	void Render();

private:
	D3DXMATRIX mD3DMatrix;
};