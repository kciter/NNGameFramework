
/**
 * NNObject.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 05
 */

#include "NNObject.h"

NNObject::NNObject()
	: mpParent(nullptr),
	mPosition(0.f,0.f), mCenter(0.f,0.f),
	mScaleX(1.f), mScaleY(1.f), mRotation(0.f), mZindex(0),
	mVisible(true)
{
}
NNObject::~NNObject()
{
	for (auto& iter=mChildList.begin(); iter!=mChildList.end(); iter++ )
	{
		SafeDelete( *iter );
	}
	mChildList.clear();
}

void NNObject::Render()
{
	if ( mVisible == false ) return;

	mMatrix = NNMatrix::Translate( -mCenter.GetX(), -mCenter.GetY() ) * 
		NNMatrix::Scale( mScaleX, mScaleY ) *
		NNMatrix::Rotation( mRotation ) *
		NNMatrix::Translate( mPosition.GetX(), mPosition.GetY() );

	if( mpParent )
	{
		mMatrix = mMatrix * mpParent->GetMatrix();
	}

	for (const auto& child : mChildList )
	{
		if ( child->IsVisible() == true )
		{
			child->Render();
		}
	}
}
void NNObject::Update( float dTime )
{
	if ( mVisible == false ) return;

	for (const auto& child : mChildList)
	{
		if ( child->IsVisible() == true )
		{
			child->Update( dTime );
		}
	}
}
void NNObject::SortingChildByZindex()
{
	mChildList.sort([](const NNObject* object1, const NNObject* object2) -> bool {
		return object1->GetZindex() < object2->GetZindex();
	});
}
void NNObject::AddChild( NNObject* object )
{
	object->SetParent( this );
	mChildList.push_back( object );
}
void NNObject::AddChild( NNObject* object, int zindex )
{
	object->SetParent( this );
	object->SetZindex( zindex );
	mChildList.push_back( object );
	SortingChildByZindex();
}
void NNObject::RemoveChild( NNObject* object, bool memoryDel )
{
	for (auto& iter=mChildList.begin(); iter!=mChildList.end(); iter++ )
	{
		if ( (*iter) == object )
		{
			if ( memoryDel == true )
			{
				SafeDelete( *iter );
			}
			mChildList.erase( iter );
			break;
		}
	}
}


