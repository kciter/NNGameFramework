
/**
 * NNSceneDirector.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNSceneDirector.h"

NNSceneDirector* NNSceneDirector::m_pInstance = nullptr;

NNSceneDirector::NNSceneDirector()
	: m_NowScene(nullptr)
{
}
NNSceneDirector::~NNSceneDirector()
{
	Release();
}

NNSceneDirector* NNSceneDirector::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new NNSceneDirector();
	}

	return m_pInstance;
}
void NNSceneDirector::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

bool NNSceneDirector::Init()
{
	m_NowScene = nullptr;
	return true;
}

bool NNSceneDirector::Release()
{
	SafeDelete( m_NowScene );
	return true;
}

bool NNSceneDirector::ChangeScene( NNScene* scene )
{
	if ( m_NowScene == nullptr )
	{
		m_NowScene = scene;
	}
	else
	{
		SafeDelete( m_NowScene );
		m_NowScene = scene;
	}

	scene->Init();

	return true;
}
bool NNSceneDirector::RenderScene()
{
	if ( m_NowScene == nullptr )
		return false;

	m_NowScene->Render();

	return true;
}
bool NNSceneDirector::UpdateScene( float dTime )
{
	if ( m_NowScene == nullptr )
		return false;

	m_NowScene->Update( dTime );

	return true;
}


