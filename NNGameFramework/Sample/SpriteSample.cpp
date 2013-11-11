
#include "SpriteSample.h"
#include "NNInputSystem.h"

SpriteSample::SpriteSample()
{
	m_Object = new NNObject();

	m_Sprite = NNSprite::Create( L"Resources/Texture/character.png" );
//	AddChild( m_Sprite );

	m_Object->SetPosition( 300.f, 300.f );

	m_Object->SetCenter( 211.f/2.f, 274.f/2.f );
	//m_Object->SetScale( 2.f, 2.f );
	m_Object->SetRotation( 90.f );

	m_Object->AddChild( m_Sprite );

	AddChild(m_Object);

	m_Sprite2 = NNSprite::Create( L"Resources/Texture/walk_0.png" );
	m_Object->AddChild( m_Sprite2 );

	m_Sprite2->SetPosition( 211.f, 0.f );

	m_Sprite2->SetCenter( 19.f, 24.f );

	// 간단한 스프라이트 출력 예제
}
SpriteSample::~SpriteSample()
{

}

void SpriteSample::Render()
{
	NNScene::Render();
}

void SpriteSample::Update( float dTime )
{
	NNScene::Update(dTime);

	if ( NNInputSystem::GetInstance()->GetKeyState(VK_UP) == KEY_PRESSED )
	{
		m_Object->SetRotation( m_Object->GetRotation() + dTime*10.f );
		m_Sprite2->SetRotation( m_Object->GetRotation() + dTime*10.f );
	}
}