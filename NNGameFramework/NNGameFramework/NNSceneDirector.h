
/**
 * NNSceneDirector.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
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


