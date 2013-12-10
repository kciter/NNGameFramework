
/**
 * NNCamera.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNPoint.h"

enum CameraAnchor
{
	TOP_LEFT,
	TOP_CENTER,
	TOP_RIGHT,
	MIDDLE_LEFT,
	MIDDLE_CENTER,
	MIDDLE_RIGHT,
	BOTTOmLEFT,
	BOTTOmCENTER,
	BOTTOmRIGHT,
	CUSTOM,
};

class NNCamera
{
public:
	NNCamera();
	~NNCamera();

	void Init(){}

	CameraAnchor GetAnchorStatus() const { return mAnchor; }
	NNPoint GetPosition() { return mPosition; }
	float GetPositionX() const { return mPosition.GetX(); }
	float GetPositionY() const { return mPosition.GetY(); }
	NNPoint GetCenter() { return mCenter; }
	float GetCenterX() const { return mCenter.GetX(); }
	float GetCenterY() const { return mCenter.GetY(); }
	float GetRotation() const { return mRotation; }
	float GetZoom() const { return mZoom; }
	int GetScreenWidth() const { return mScreenWidth; }
	int GetScreenHeight() const { return mScreenHeight; }

	void SetPosition( NNPoint position ) { mPosition = position; }
	void SetPosition( float x, float y ) { mPosition = NNPoint(x,y); }
	void SetRotation( float rotation ) { mRotation = rotation; }
	void SetZoom( float zoom ) { mZoom = zoom; }
	void SetCenter( NNPoint center )
	{
		mCenter = center;
		mAnchor = CameraAnchor::CUSTOM;
	}
	void SetCenter( float x, float y )
	{
		mCenter = NNPoint( x, y );
		mAnchor = CameraAnchor::CUSTOM;
	}
	void SetCameraAnchor( CameraAnchor anchor )
	{
		mAnchor = anchor;

		switch ( anchor )
		{
		case CameraAnchor::TOP_LEFT:
			mCenter = NNPoint(0.f,0.f);
			break;
		case CameraAnchor::TOP_CENTER:
			mCenter = NNPoint((float)mScreenWidth/2.f, 0.f);
			break;
		case CameraAnchor::TOP_RIGHT:
			mCenter = NNPoint((float)mScreenWidth, 0.f);
			break;
		case CameraAnchor::MIDDLE_LEFT:
			mCenter = NNPoint(0.f, (float)mScreenHeight/2.f);
			break;
		case CameraAnchor::MIDDLE_CENTER:
			mCenter = NNPoint((float)mScreenWidth/2.f, (float)mScreenHeight/2.f);
			break;
		case CameraAnchor::MIDDLE_RIGHT:
			mCenter = NNPoint((float)mScreenWidth, (float)mScreenHeight/2.f);
			break;
		case CameraAnchor::BOTTOmLEFT:
			mCenter = NNPoint(0.f, (float)mScreenHeight);
			break;
		case CameraAnchor::BOTTOmCENTER:
			mCenter = NNPoint((float)mScreenWidth/2.f, (float)mScreenHeight);
			break;
		case CameraAnchor::BOTTOmRIGHT:
			mCenter = NNPoint((float)mScreenWidth, (float)mScreenHeight);
			break;
		}
	}

private:
	CameraAnchor mAnchor;

	NNPoint mPosition;
	NNPoint mCenter;
	float mRotation;
	float mZoom;
	int mScreenWidth;
	int mScreenHeight;
};