
/**
 * NNSceneDirector.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNSceneDirector.h"

NNSceneDirector* NNSceneDirector::mpInstance = nullptr;

NNSceneDirector::NNSceneDirector()
	: mNowScene(nullptr)
{
}
NNSceneDirector::~NNSceneDirector()
{
	Release();
}

NNSceneDirector* NNSceneDirector::GetInstance()
{
	if ( mpInstance == nullptr )
	{
		mpInstance = new NNSceneDirector();
	}

	return mpInstance;
}
void NNSceneDirector::ReleaseInstance()
{
	if ( mpInstance != nullptr )
	{
		delete mpInstance;
		mpInstance = nullptr;
	}
}

bool NNSceneDirector::Init()
{
	mNowScene = nullptr;
	return true;
}

bool NNSceneDirector::Release()
{
	SafeDelete( mNowScene );
	return true;
}

bool NNSceneDirector::ChangeScene( NNScene* scene )
{
	if ( mNowScene == nullptr )
	{
		mNowScene = scene;
	}
	else
	{
		SafeDelete( mNowScene );
		mNowScene = scene;
	}

	scene->Init();

	return true;
}
bool NNSceneDirector::RenderScene()
{
	if ( mNowScene == nullptr )
		return false;

	mNowScene->Render();

	return true;
}
bool NNSceneDirector::UpdateScene( float dTime )
{
	if ( mNowScene == nullptr )
		return false;

	mNowScene->Update( dTime );

	return true;
}


