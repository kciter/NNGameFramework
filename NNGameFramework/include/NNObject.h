
/**
 * NNObject.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 05
 */

#pragma once

#include "NNConfig.h"
#include "NNMatrix.h"
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