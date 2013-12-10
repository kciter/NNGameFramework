
/**
 * NNSceneDirector.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNScene.h"
#include "NNConfig.h"

class NNSceneDirector
{
private:
	static NNSceneDirector* mpInstance;

private:
	NNSceneDirector();
	~NNSceneDirector();

public:
	static NNSceneDirector* GetInstance();
	static void ReleaseInstance();

private:
	NNScene* mNowScene;

public:
	bool Init();
	bool Release();
	
	NNScene* GetNowScene() { return mNowScene; }

public:
	bool ChangeScene( NNScene* scene );
	bool RenderScene();
	bool UpdateScene( float dTime );
};


