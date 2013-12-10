
/**
 * NNParticle.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNConfig.h"
#include "NNPoint.h"
#include "NNSize.h"
#include "NNColor.h"
#include "NNMatrix.h"

#include "NND2DRenderer.h"
#include "NND3DRenderer.h"
#include "NNTexture.h"

class NNParticle
{
public:
	NNParticle()
	 : mPosition(0.f,0.f), mStartScaleX(0.f), mStartScaleY(0.f), mEndScaleX(0.f), mEndScaleY(0.f), 
	   mImageWidth(0.f), mImageHeight(0.f), mStartRotationSpeed(0.f), mEndRotationSpeed(0.f),
	   mLifeTime(0.f), mNowLifeTime(0.f), mVisible(true),
	   mStartColor(255,255,255,1.f), mEndColor(255,255,255,1.f),
	   mSpeed(0.f), mScaleX(1.f), mScaleY(1.f), mRotation(0.f), mRotationSpeed(0.f), mColor(255,255,255,1.f) {}
	virtual ~NNParticle(){}

	static NNParticle* Create( std::wstring path );
	virtual void Destroy() = 0;

	virtual void Render();
	virtual void Update( float dTime );

public:
	void SetParentMatrix( NNMatrix matrix ) { mParentMatrix = matrix; }
	void SetPosition( NNPoint position ) { mPosition = position; }
	void SetPosition( float x, float y ) { mPosition.SetPoint(x,y); }
	void SetStartSpeed( float speed ) { mStartSpeed = speed; }
	void SetEndSpeed( float speed ) { mEndSpeed = speed; }
	void SetStartScaleX( float scaleX ) { mStartScaleX = scaleX; }
	void SetStartScaleY( float scaleY ) { mStartScaleY = scaleY; }
	void SetEndScaleX( float scaleX ) { mEndScaleX = scaleX; }
	void SetEndScaleY( float scaleY ) { mEndScaleY = scaleY; }
	void SetStartScale( float scaleX, float scaleY ) { mStartScaleX = scaleX; mStartScaleY = scaleY; }
	void SetEndScale( float scaleX, float scaleY ) { mEndScaleX = scaleX; mEndScaleY = scaleY; }
	void SetStartRotationSpeed( float rotation ) { mStartRotationSpeed = rotation; }
	void SetEndRotationSpeed( float rotation ) { mEndRotationSpeed = rotation; }
	void SetVisible( bool visible ) { mVisible = visible; }
	void SetLifeTime( float lifetime ) { mLifeTime = lifetime; }
	void SetStartColor( NNColor color ) { mStartColor = color; }
	void SetStartColor( int r, int g, int b, float opacity ) { mStartColor = NNColor(r,g,b,opacity); }
	void SetStartRGB( int r, int g, int b ) { mStartColor = NNColor(r,g,b,1.f); }
	void SetStartRGBA( int r, int g, int b, int a ) { mStartColor = NNColor(r,g,b,a); }
	void SetEndColor( NNColor color ) { mEndColor = color; }
	void SetEndColor( int r, int g, int b, float opacity ) { mEndColor = NNColor(r,g,b,opacity); }
	void SetEndRGB( int r, int g, int b ) { mEndColor = NNColor(r,g,b,1.f); }
	void SetEndRGBA( int r, int g, int b, int a ) { mEndColor = NNColor(r,g,b,a); }
	void SetDirection( float direction ) { mDirection = direction; }

	NNMatrix GetParentMatrix() const { return mParentMatrix; }
	NNMatrix GetMatrix() const { return mMatrix; }
	NNPoint GetPosition() { return mPosition; }
	float GetStartSpeed() const { return mStartSpeed; }
	float GetEndSpeed() const { return mEndSpeed; }
	float GetStartScaleX() const { return mStartScaleX; }
	float GetStartScaleY() const { return mStartScaleY; }
	float GetEndScaleX() const { return mEndScaleX; }
	float GetEndScaleY() const { return mEndScaleY; }
	float GetImageWidth() const { return mImageWidth; }
	float GetImageHeight() const { return mImageHeight; }
	float GetStartRotationSpeed() const { return mStartRotationSpeed; }
	float GetEndRotationSpeed() const { return mEndRotationSpeed; }
	float GetLifeTime() const { return mLifeTime; }
	float GetNowLifeTime() const { return mNowLifeTime; }
	bool IsVisible() const { return mVisible; }
	NNColor GetStartColor() { return mStartColor; }
	NNColor GetEndColor() { return mEndColor; }
	float GetDirection() { return mDirection; }

protected:
	NNMatrix mParentMatrix;
	NNMatrix mMatrix;
	NNPoint mPosition;
	float mStartSpeed, mEndSpeed;
	float mStartScaleX, mEndScaleX;
	float mStartScaleY, mEndScaleY;
	float mImageWidth;
	float mImageHeight;
	float mStartRotationSpeed, mEndRotationSpeed; // Degree
	float mLifeTime;
	float mNowLifeTime;
	bool mVisible;
	NNColor mStartColor, mEndColor;

	float mSpeed;
	float mScaleX, mScaleY;
	float mRotation;
	float mRotationSpeed;
	float mDirection;
	NNColor mColor;
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
	NND2DRenderer* mpD2DRenderer;
	NND2DTexture* mpD2DTexture;
	D2D1::Matrix3x2F mD2DMatrix;
};

class NND3DParticle : public NNParticle
{
public:
	NND3DParticle();
	NND3DParticle( std::wstring path );
	virtual ~NND3DParticle();

	void Destroy();

	void Render();
	void Update( float dTime );

private:
	NND3DRenderer* mpD3DRenderer;
	NND3DTexture* mpD3DTexture;
	D3DXMATRIX mD3DMatrix;
};