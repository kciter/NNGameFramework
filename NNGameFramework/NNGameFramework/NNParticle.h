
#pragma once

#include "NNConfig.h"
#include "NNPoint.h"
#include "NNSize.h"
#include "NNColor.h"

#include "NND2DRenderer.h"
#include "NNTexture.h"

class NNParticle
{
public:
	NNParticle();
	virtual ~NNParticle();

	static NNParticle* Create( std::wstring path );
	virtual void Destroy() {}

	virtual void Render();
	virtual void Update( float dTime );

public:
	void SetPosition( NNPoint position ) { m_Position = position; }
	void SetPosition( float x, float y ) { m_Position.SetPoint(x,y); }
	void SetScaleX( float scaleX ) { m_ScaleX = scaleX; }
	void SetScaleY( float scaleY ) { m_ScaleY = scaleY; }
	void SetScale( float scaleX, float scaleY ) { m_ScaleX = scaleX; m_ScaleY = scaleY; }
	void SetRotation( float rotation ) { m_Rotation = rotation; }
	void SetVisible( bool visible ) { m_Visible = visible; }
	void SetColor( NNColor color ) { m_Color = color; }
	void SetColor( int r, int g, int b, float opacity ) { m_Color = NNColor(r,g,b,opacity); }
	void SetRGB( int r, int g, int b ) { m_Color = NNColor(r,g,b,1.f); }
	void SetRGBA( int r, int g, int b, int a ) { m_Color = NNColor(r,g,b,a); }

	D2D1::Matrix3x2F GetMatrix() const { return m_Matrix; }
	NNPoint GetPosition() { return m_Position; }
	float GetScaleX() const { return m_ScaleX; }
	float GetScaleY() const { return m_ScaleY; }
	float GetRotation() const { return m_Rotation; }
	bool IsVisible() const { return m_Visible; }
	NNColor GetColor() { return m_Color; }

private:
	D2D1::Matrix3x2F m_Matrix;
	NNPoint m_Position;
	float m_ScaleX;
	float m_ScaleY;
	float m_Rotation; // Degree
	bool m_Visible;
	NNColor m_Color;
};

class NND2DParticle : public NNParticle
{
public:
	NND2DParticle();
	virtual ~NND2DParticle();

	void Destroy();

	void Render();
	void Update( float dTime );

private:
	NND2DRenderer* m_pD2DRenderer;
	NND2DTexture* m_pD2DTexture;
};