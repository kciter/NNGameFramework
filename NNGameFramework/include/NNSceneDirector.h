
#pragma once

#include "NNScene.h"
#include "NNConfig.h"

/* */
/* NNSceneDirector
/* 생성된 씬을 관리하는 싱글톤 클래스
/* 등록된 씬을 출력, 처리하는 역활이다.
/* */

class NNSceneDirector
{
private:
	static NNSceneDirector* m_pInstance;

private:
	NNSceneDirector();
	~NNSceneDirector();

public:
	static NNSceneDirector* GetInstance();
	static void ReleaseInstance();

private:
	NNScene* m_NowScene;

public:
	bool Init();
	bool Release();

public:
	bool ChangeScene( NNScene* scene );
	bool RenderScene();
	bool UpdateScene( float dTime );
};


