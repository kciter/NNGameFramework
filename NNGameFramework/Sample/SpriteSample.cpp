
#include "SpriteSample.h"
#include "NNInputSystem.h"

SpriteSample::SpriteSample()
{
}
SpriteSample::~SpriteSample()
{

}

void SpriteSample::Init()
{
	m_Sprite = NNSprite::Create( L"Resources/Texture/map.png" );
	m_Sprite->SetPosition(100.f,100.f);
	AddChild( m_Sprite );

	// ������ ��������Ʈ ��� ����
}

void SpriteSample::Render()
{
	NNScene::Render();
}

void SpriteSample::Update( float dTime )
{
	NNScene::Update(dTime);
}