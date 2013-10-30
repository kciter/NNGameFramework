
#include "SpriteExampleScene.h"

SpriteExampleScene::SpriteExampleScene()
{
	m_Sprite = NNSprite::Create( L"Resources/Texture/SpriteExample.jpg" );
	AddChild( m_Sprite );
}
SpriteExampleScene::~SpriteExampleScene()
{

}

void SpriteExampleScene::Render()
{
	NNObject::Render();
}

void SpriteExampleScene::Update( float dTime )
{
	NNObject::Update(dTime);
}