
#include "TestSample.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "ParticleSample.h"

TestSample::TestSample()
	: m_SceneState(0), m_Sprite(nullptr), m_Sprite2(nullptr)
{
	m_Sprite = NNSprite::Create( L"Resources/Texture/character.png" );
	m_Sprite2 = NNSprite::Create( L"Resources/Texture/map.png" );

	AddChild( m_Sprite );
	AddChild( m_Sprite2 );
}
TestSample::~TestSample()
{

}

void TestSample::Render()
{
	NNScene::Render();
}
void TestSample::Update( float dTime )
{
	NNScene::Update( dTime );

	switch ( m_SceneState )
	{
	case 0:
		{
			m_Sprite->SetVisible(true);
			m_Sprite2->SetVisible(false);
			break;
		}
	case 1:
		{
			m_Sprite->SetVisible(false);
			m_Sprite2->SetVisible(true);
			break;
		}
	}

	if ( NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_UP )
	{
		m_SceneState++;

		if ( m_SceneState == 2 )
		{
			NNSceneDirector::GetInstance()->ChangeScene( ParticleSample::Create() );
			return;
		}
	}
}