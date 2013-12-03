
/**
 * NNObject.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#pragma once

#include "NNConfig.h"
#include "NNPoint.h"
#include "NNSize.h"

/* */
/* NNObject
/* ���� �ٽ��� �Ǵ� ���
/* Ʈ�� ������ �̷���ִ�.
/* ��带 ������ �� �ڽ� ��嵵 delete ���ֱ� ������
/* ���� �ֻ��� ��常 delete�ص� �˾Ƽ� �޸𸮸� �������ش�.
/* SceneDirector���� �ֻ��� ��带 �������ֱ� ������
/* �����ڴ� Add�� ���൵ �˾Ƽ� �޸� ������ ���ش�.
/* ������ �޸� ������ �׻� üũ �� ��
/* */

class NNObject
{
public:
	NNObject();
	virtual ~NNObject();

public:
	virtual void Render();
	virtual void Update( float dTime );

	virtual void Init() = 0;

	NNObject* GetParent() { return m_pParent; }
	std::list<NNObject*> GetChildList() { return m_ChildList; }

	void SetParent( NNObject* object ) { m_pParent = object; }

	void AddChild( NNObject* object );
	void AddChild( NNObject* object, int zindex );
	void RemoveChild( NNObject* object, bool memoryDel=true );

	void SortingChildByZindex();

	inline D2D1::Matrix3x2F GetMatrix() const { return m_Matrix; }
	inline NNPoint GetPosition() { return m_Position; }
	inline float GetPositionX() const { return m_Position.GetX(); }
	inline float GetPositionY() const { return m_Position.GetY(); }
	inline NNPoint GetCenter() { return m_Center; }
	inline float GetCenterX() const { return m_Center.GetX(); }
	inline float GetCenterY() const { return m_Center.GetY(); }
	inline float GetScaleX() const { return m_ScaleX; }
	inline float GetScaleY() const { return m_ScaleY; }
	inline float GetRotation() const { return m_Rotation; }
	inline int GetZindex() const { return m_Zindex; }
	inline bool IsVisible() const { return m_Visible; }

	void SetPosition( float x, float y ) { m_Position = NNPoint(x,y); }
	void SetPosition( NNPoint point ) { m_Position = point; }
	void SetCenter( float x, float y ) { m_Center = NNPoint(x,y); }
	void SetCenter( NNPoint point ) { m_Center = point; }
	void SetScale( float scaleX, float scaleY ) { 
		m_ScaleX = scaleX; 
		m_ScaleY = scaleY;
	}
	void SetScaleX( float scaleX ) { m_ScaleX = scaleX; }
	void SetScaleY( float scaleY ) { m_ScaleY = scaleY; }
	void SetRotation( float rotation ) { m_Rotation = rotation; }
	void SetZindex( int zindex ) { m_Zindex = zindex; }
	void SetVisible( bool visible ) { m_Visible = visible; SortingChildByZindex(); }

protected:
	NNObject* m_pParent;
	std::list<NNObject*> m_ChildList;

protected:
	D2D1::Matrix3x2F m_Matrix;
	NNPoint m_Position;
	NNPoint m_Center;
	float m_ScaleX;
	float m_ScaleY;
	float m_Rotation; // Degree
	NNSize m_Size;
	int m_Zindex;
	int m_ZindexCount;
	bool m_Visible;
};