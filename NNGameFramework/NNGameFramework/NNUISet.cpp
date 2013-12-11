
/**
 * NNUISet.cpp
 * 작성자: 이선협
 * 작성일: 2013. 11. 25
 * 마지막으로 수정한 사람: 이선협
 * 수정이유: IsVisible과 상관없이 출력되던 문제 수정
 * 수정일: 2013. 12. 11
 */

#include "NNUISet.h"

NNUISet::NNUISet()
{
}
NNUISet::~NNUISet()
{

}

void NNUISet::Render()
{
	if ( mVisible == false ) return;

	mMatrix = NNMatrix::Translate( -mCenter.GetX(), -mCenter.GetY() )* 
		NNMatrix::Rotation( mRotation ) *
		NNMatrix::Scale( mScaleX, mScaleY ) *
		NNMatrix::Translate( mPosition.GetX(), mPosition.GetY() );

	for (const auto& child : mChildList )
	{
		if ( child->IsVisible() == true )
		{
			child->Render();
		}
	}
}
void NNUISet::Update( float dTime )
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