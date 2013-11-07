
#pragma once

#include "NNConfig.h"
#include "NNPoint.h"
#include "NNSize.h"

/* */
/* NNObject
/* 가장 핵심이 되는 노드
/* 트리 구조를 이루고있다.
/* 노드를 삭제할 때 자식 노드도 delete 해주기 때문에
/* 가장 최상위 노드만 delete해도 알아서 메모리를 삭제해준다.
/* SceneDirector에서 최상위 노드를 삭제해주기 때문에
/* 개발자는 Add만 해줘도 알아서 메모리 관리를 해준다.
/* 하지만 메모리 누수는 항상 체크 할 것
/* */

class NNObject
{
public:
	NNObject();
	virtual ~NNObject();

public:
	virtual void Render();
	virtual void Update( float dTime );

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


