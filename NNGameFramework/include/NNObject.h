
/**
 * NNObject.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 05
 */

#pragma once

#include "NNConfig.h"
#include "NNMatrix.h"
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

	NNObject* GetParent() { return mpParent; }
	std::list<NNObject*> GetChildList() { return mChildList; }

	void SetParent( NNObject* object ) { mpParent = object; }

	void AddChild( NNObject* object );
	void AddChild( NNObject* object, int zindex );
	void RemoveChild( NNObject* object, bool memoryDel=true );

	void SortingChildByZindex();

	inline NNMatrix GetMatrix() const { return mMatrix; }
	inline NNPoint GetPosition() { return mPosition; }
	inline float GetPositionX() const { return mPosition.GetX(); }
	inline float GetPositionY() const { return mPosition.GetY(); }
	inline NNPoint GetCenter() { return mCenter; }
	inline float GetCenterX() const { return mCenter.GetX(); }
	inline float GetCenterY() const { return mCenter.GetY(); }
	inline float GetScaleX() const { return mScaleX; }
	inline float GetScaleY() const { return mScaleY; }
	inline float GetRotation() const { return mRotation; }
	inline int GetZindex() const { return mZindex; }
	inline bool IsVisible() const { return mVisible; }

	void SetPosition( float x, float y ) { mPosition = NNPoint(x,y); }
	void SetPosition( NNPoint point ) { mPosition = point; }
	void SetCenter( float x, float y ) { mCenter = NNPoint(x,y); }
	void SetCenter( NNPoint point ) { mCenter = point; }
	void SetScale( float scaleX, float scaleY ) { 
		mScaleX = scaleX; 
		mScaleY = scaleY;
	}
	void SetScaleX( float scaleX ) { mScaleX = scaleX; }
	void SetScaleY( float scaleY ) { mScaleY = scaleY; }
	void SetRotation( float rotation ) { mRotation = rotation; }
	void SetZindex( int zindex ) { mZindex = zindex; SortingChildByZindex(); }
	void SetVisible( bool visible ) { mVisible = visible; }

protected:
	NNObject* mpParent;
	std::list<NNObject*> mChildList;

protected:
	NNMatrix mMatrix;
	NNPoint mPosition;
	NNPoint mCenter;
	float mScaleX;
	float mScaleY;
	float mRotation; // Degree
	NNSize mSize;
	int mZindex;
	int mZindexCount;
	bool mVisible;
};