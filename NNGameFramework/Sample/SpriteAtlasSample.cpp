
#include "SpriteAtlasSample.h"

SpriteAtlasSample::SpriteAtlasSample()
{
	m_SpriteAtlas = NNSpriteAtlas::Create(L"Resources/Texture/map.png");
	AddChild(m_SpriteAtlas);

	m_SpriteAtlas->SetCutSize(0,0,100.f,100.f);
	m_SpriteAtlas->SetPosition(100.f,100.f);

	// 이미지를 0,0에서 100,100으로 자른 이미지를 출력
	// 이 노드의 사용법은 Atlas 검색
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