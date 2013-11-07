
#ifdef _DEBUG

#include "SpriteAtlasSample.h"

SpriteAtlasSample::SpriteAtlasSample()
{
	m_SpriteAtlas = NNSpriteAtlas::Create(L"Sprite/map.png");
	AddChild(m_SpriteAtlas);

	m_SpriteAtlas->SetCutSize(0,0,100.f,100.f);
	m_SpriteAtlas->SetPosition(100.f,100.f);
}

SpriteAtlasSample::~SpriteAtlasSample()
{

}

void SpriteAtlasSample::Render()
{
	NNScene::Render();
}

void SpriteAtlasSample::Update( float dTime )
{
	NNScene::Update(dTime);
}

#endif