#pragma once

#include "NNScene.h"
#include "NNConfig.h"

/* */
/* NNSceneDirector
/* ������ ���� �����ϴ� �̱��� Ŭ����
/* ���ϵ� ���� ����, ó���ϴ� ��Ȱ�̴�.
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
	
	NNScene* GetNowScene() { return m_NowScene; }

public:
	bool ChangeScene( NNScene* scene );
	bool RenderScene();
	bool UpdateScene( float dTime );
};


