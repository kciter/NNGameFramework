
/**
 * NNScene.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 05
 */

#include "NNScene.h"

NNScene::NNScene()
	: mUISet(nullptr)
{
}
NNScene::~NNScene()
{
	SafeDelete(mUISet);
}

void NNScene::Render()
{
	if ( mVisible == false ) return;

	mMatrix = NNMatrix::Translate( (int)mCamera.GetCenterX(), (int)mCamera.GetCenterY() ) *
		NNMatrix::Scale( mCamera.GetZoom(), mCamera.GetZoom() ) *
		NNMatrix::Rotation( mCamera.GetRotation() ) *
		NNMatrix::Translate( (int)-mCamera.GetPositionX(), (int)-mCamera.GetPositionY());

	for (const auto& child : mChildList )
	{
		if ( child->IsVisible() == true )
		{
			child->Render();
		}
	}

	if ( mUISet != nullptr )
	{
		if ( mUISet->IsVisible() == true )
		{
			mUISet->Render();
		}
	}
}
void NNScene::Update( float dTime )
{
	if ( mVisible == false ) return;

	for (const auto& child : mChildList)
	{
		if ( child->IsVisible() == true )
		{
			child->Update( dTime );
		}
	}

	if ( mUISet != nullptr )
	{
		if ( mUISet->IsVisible() == true )
		{
			mUISet->Update( dTime );
		}
	}
}