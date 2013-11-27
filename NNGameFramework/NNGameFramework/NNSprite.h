
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
	float m_ImageWidth;
	float m_ImageHeight;
	float m_ColorR, m_ColorG, m_ColorB;
	float m_Opacity;
public:
	NNSprite()
		: m_ImageWidth(0.f), m_ImageHeight(0.f),
		  m_ColorR(0.f), m_ColorG(0.f), m_ColorB(0.f), m_Opacity(1.f)
	{}
	virtual ~NNSprite(){}

public:
	//static NNSprite* Create();
	static NNSprite* Create( std::wstring path );
	static NNSprite* Create( NNZip *buf );
	virtual void Destroy() {}
	virtual void Render() {}

public:
	inline float GetImageWidth() const { return m_ImageWidth; }
	inline float GetImageHeight() const { return m_ImageHeight; }
	inline float GetOpacity() const { return m_Opacity; }

	void SetImageWidth( float width ) { m_ImageWidth = width; }
	void SetImageHeight( float height ) { m_ImageHeight = height; }
	void SetOpacity( float opacity ) { m_Opacity = opacity; }
};

class NND2DSprite : public NNSprite
{
private:
	NND2DRenderer* m_pD2DRenderer;
	NND2DTexture* m_pD2DTexture;

public:
	NND2DSprite();
	NND2DSprite( std::wstring path );
	NND2DSprite( NNZip *buf );
	virtual ~NND2DSprite();

	void Destroy();
	void Render();
};

class NND3DSprite : public NNSprite
{
private:
	NND3DRenderer* mpD3DRenderer;
	NND3DTexture* mpD3DTexture;

public:
	NND3DSprite();
	NND3DSprite( std::wstring path );
	virtual ~NND3DSprite();

	void Destroy();
	void Render();
};