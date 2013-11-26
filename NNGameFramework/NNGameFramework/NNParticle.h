
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
	NNParticle()
	 : m_Position(0.f,0.f), m_StartScaleX(0.f), m_StartScaleY(0.f), m_EndScaleX(0.f), m_EndScaleY(0.f), 
	   m_ImageWidth(0.f), m_ImageHeight(0.f), m_StartRotationSpeed(0.f), m_EndRotationSpeed(0.f),
	   m_LifeTime(0.f), m_NowLifeTime(0.f), m_Visible(true),
	   m_StartColor(255,255,255,1.f), m_EndColor(255,255,255,1.f),
	   m_Speed(0.f), m_ScaleX(1.f), m_ScaleY(1.f), m_Rotation(0.f), m_RotationSpeed(0.f), m_Color(255,255,255,1.f) {}
	virtual ~NNParticle(){}

	static NNParticle* Create( std::wstring path );
	virtual void Destroy() = 0;

	virtual void Render();
	virtual void Update( float dTime );

public:
	void SetParentMatrix( D2D1::Matrix3x2F matrix ) { m_ParentMatrix = matrix; }
	void SetPosition( NNPoint position ) { m_Position = position; }
	void SetPosition( float x, float y ) { m_Position.SetPoint(x,y); }
	void SetStartSpeed( float speed ) { m_StartSpeed = speed; }
	void SetEndSpeed( float speed ) { m_EndSpeed = speed; }
	void SetStartScaleX( float scaleX ) { m_StartScaleX = scaleX; }
	void SetStartScaleY( float scaleY ) { m_StartScaleY = scaleY; }
	void SetEndScaleX( float scaleX ) { m_EndScaleX = scaleX; }
	void SetEndScaleY( float scaleY ) { m_EndScaleY = scaleY; }
	void SetStartScale( float scaleX, float scaleY ) { m_StartScaleX = scaleX; m_StartScaleY = scaleY; }
	void SetEndScale( float scaleX, float scaleY ) { m_EndScaleX = scaleX; m_EndScaleY = scaleY; }
	void SetStartRotationSpeed( float rotation ) { m_StartRotationSpeed = rotation; }
	void SetEndRotationSpeed( float rotation ) { m_EndRotationSpeed = rotation; }
	void SetVisible( bool visible ) { m_Visible = visible; }
	void SetLifeTime( float lifetime ) { m_LifeTime = lifetime; }
	void SetStartColor( NNColor color ) { m_StartColor = color; }
	void SetStartColor( int r, int g, int b, float opacity ) { m_StartColor = NNColor(r,g,b,opacity); }
	void SetStartRGB( int r, int g, int b ) { m_StartColor = NNColor(r,g,b,1.f); }
	void SetStartRGBA( int r, int g, int b, int a ) { m_StartColor = NNColor(r,g,b,a); }
	void SetEndColor( NNColor color ) { m_EndColor = color; }
	void SetEndColor( int r, int g, int b, float opacity ) { m_EndColor = NNColor(r,g,b,opacity); }
	void SetEndRGB( int r, int g, int b ) { m_EndColor = NNColor(r,g,b,1.f); }
	void SetEndRGBA( int r, int g, int b, int a ) { m_EndColor = NNColor(r,g,b,a); }
	void SetDirection( float direction ) { m_Direction = direction; }

	D2D1::Matrix3x2F GetParentMatrix() const { return m_ParentMatrix; }
	D2D1::Matrix3x2F GetMatrix() const { return m_Matrix; }
	NNPoint GetPosition() { return m_Position; }
	float GetStartSpeed() const { return m_StartSpeed; }
	float GetEndSpeed() const { return m_EndSpeed; }
	float GetStartScaleX() const { return m_StartScaleX; }
	float GetStartScaleY() const { return m_StartScaleY; }
	float GetEndScaleX() const { return m_EndScaleX; }
	float GetEndScaleY() const { return m_EndScaleY; }
	float GetImageWidth() const { return m_ImageWidth; }
	float GetImageHeight() const { return m_ImageHeight; }
	float GetStartRotationSpeed() const { return m_StartRotationSpeed; }
	float GetEndRotationSpeed() const { return m_EndRotationSpeed; }
	float GetLifeTime() const { return m_LifeTime; }
	float GetNowLifeTime() const { return m_NowLifeTime; }
	bool IsVisible() const { return m_Visible; }
	NNColor GetStartColor() { return m_StartColor; }
	NNColor GetEndColor() { return m_EndColor; }
	float GetDirection() { return m_Direction; }

protected:
	D2D1::Matrix3x2F m_ParentMatrix;
	D2D1::Matrix3x2F m_Matrix;
	NNPoint m_Position;
	float m_StartSpeed, m_EndSpeed;
	float m_StartScaleX, m_EndScaleX;
	float m_StartScaleY, m_EndScaleY;
	float m_ImageWidth;
	float m_ImageHeight;
	float m_StartRotationSpeed, m_EndRotationSpeed; // Degree
	float m_LifeTime;
	float m_NowLifeTime;
	bool m_Visible;
	NNColor m_StartColor, m_EndColor;

	float m_Speed;
	float m_ScaleX, m_ScaleY;
	float m_Rotation;
	float m_RotationSpeed;
	float m_Direction;
	NNColor m_Color;
};

class NND2DParticle : public NNParticle
{
public:
	NND2DParticle();
	NND2DParticle( std::wstring path );
	virtual ~NND2DParticle();

	void Destroy();

	void Render();
	void Update( float dTime );

private:
	NND2DRenderer* m_pD2DRenderer;
	NND2DTexture* m_pD2DTexture;
};