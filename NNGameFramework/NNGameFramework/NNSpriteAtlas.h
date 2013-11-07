
#pragma once

#include "NNObject.h"
#include "NNConfig.h"

#include "NNTexture.h"
#include "NND2DRenderer.h"

class NNSpriteAtlas : public NNObject
{
public:
	NNSpriteAtlas()
		: m_ImageWidth(0.f), m_ImageHeight(0.f),
		m_ColorR(0.f), m_ColorG(0.f), m_ColorB(0.f), m_Opacity(1.f){}
	virtual ~NNSpriteAtlas(){}

	void Render(){}
	void Update( float dTime ){}

	static NNSpriteAtlas* Create( std::wstring path );

	inline float GetImageWidth() const { return m_ImageWidth; }
	inline float GetImageHeight() const { return m_ImageHeight; }
	inline float GetOpacity() const { return m_Opacity; }

	void SetImageWidth( float width ) { m_ImageWidth = width; }
	void SetImageHeight( float height ) { m_ImageHeight = height; }
	void SetOpacity( float opacity ) { m_Opacity = opacity; }
	void SetCutSize( float leftX, float topY, float rightX, float bottomY ) { m_CutLeftX=leftX; m_CutTopY=topY; m_CutRightX=rightX; m_CutBottomY=bottomY; }

protected:
	float m_ImageWidth;
	float m_ImageHeight;
	float m_ColorR, m_ColorG, m_ColorB;
	float m_Opacity;
	float m_CutLeftX, m_CutTopY, m_CutRightX, m_CutBottomY;
};

class NND2DSpriteAtlas : public NNSpriteAtlas
{
private:
	NND2DRenderer* m_pD2DRenderer;
	NND2DTexture* m_pD2DTexture;

public:
	NND2DSpriteAtlas();
	NND2DSpriteAtlas( std::wstring path );
	virtual ~NND2DSpriteAtlas();

	void Destroy();
	void Render();
};