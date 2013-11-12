
#include "SpriteSample.h"
#include "NNInputSystem.h"

SpriteSample::SpriteSample()
{
	m_Sprite = NNSprite::Create( L"Resources/Texture/character.png" );
	AddChild( m_Sprite );

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
}