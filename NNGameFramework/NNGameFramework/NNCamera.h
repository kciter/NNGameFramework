
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
	BOTTOM_LEFT,
	BOTTOM_CENTER,
	BOTTOM_RIGHT,
	CUSTOM,
};

class NNCamera
{
public:
	NNCamera();
	~NNCamera();

	CameraAnchor GetAnchorStatus() const { return m_Anchor; }
	NNPoint GetPosition() { return m_Position; }
	float GetPositionX() const { return m_Position.GetX(); }
	float GetPositionY() const { return m_Position.GetY(); }
	NNPoint GetCenter() { return m_Center; }
	float GetCenterX() const { return m_Center.GetX(); }
	float GetCenterY() const { return m_Center.GetY(); }
	float GetRotation() const { return m_Rotation; }
	float GetZoom() const { return m_Zoom; }
	int GetScreenWidth() const { return m_ScreenWidth; }
	int GetScreenHeight() const { return m_ScreenHeight; }

	void SetPosition( NNPoint position ) { m_Position = position; }
	void SetPosition( float x, float y ) { m_Position = NNPoint(x,y); }
	void SetRotation( float rotation ) { m_Rotation = rotation; }
	void SetZoom( float zoom ) { m_Zoom = zoom; }
	void SetCenter( NNPoint center )
	{
		m_Center = center;
		m_Anchor = CameraAnchor::CUSTOM;
	}
	void SetCenter( float x, float y )
	{
		m_Center = NNPoint( x, y );
		m_Anchor = CameraAnchor::CUSTOM;
	}
	void SetCameraAnchor( CameraAnchor anchor )
	{
		m_Anchor = anchor;

		switch ( anchor )
		{
		case CameraAnchor::TOP_LEFT:
			m_Center = NNPoint(0.f,0.f);
			break;
		case CameraAnchor::TOP_CENTER:
			m_Center = NNPoint((float)m_ScreenWidth/2.f, 0.f);
			break;
		case CameraAnchor::TOP_RIGHT:
			m_Center = NNPoint((float)m_ScreenWidth, 0.f);
			break;
		case CameraAnchor::MIDDLE_LEFT:
			m_Center = NNPoint(0.f, (float)m_ScreenHeight/2.f);
			break;
		case CameraAnchor::MIDDLE_CENTER:
			m_Center = NNPoint((float)m_ScreenWidth/2.f, (float)m_ScreenHeight/2.f);
			break;
		case CameraAnchor::MIDDLE_RIGHT:
			m_Center = NNPoint((float)m_ScreenWidth, (float)m_ScreenHeight/2.f);
			break;
		case CameraAnchor::BOTTOM_LEFT:
			m_Center = NNPoint(0.f, (float)m_ScreenHeight);
			break;
		case CameraAnchor::BOTTOM_CENTER:
			m_Center = NNPoint((float)m_ScreenWidth/2.f, (float)m_ScreenHeight);
			break;
		case CameraAnchor::BOTTOM_RIGHT:
			m_Center = NNPoint((float)m_ScreenWidth, (float)m_ScreenHeight);
			break;
		}
	}

private:
	CameraAnchor m_Anchor;

	NNPoint m_Position;
	NNPoint m_Center;
	float m_Rotation;
	float m_Zoom;
	int m_ScreenWidth;
	int m_ScreenHeight;
};