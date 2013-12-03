
#include "SpriteAtlasSample.h"

SpriteAtlasSample::SpriteAtlasSample()
{
}

SpriteAtlasSample::~SpriteAtlasSample()
{
}

void SpriteAtlasSample::Init()
{
	m_SpriteAtlas = NNSpriteAtlas::Create(L"Resources/Texture/map.png");
	AddChild(m_SpriteAtlas);

	m_SpriteAtlas->SetCutSize(0,0,100.f,100.f);
	m_SpriteAtlas->SetPosition(100.f,100.f);

	// �̹����� 0,0���� 100,100���� �ڸ� �̹����� ���
	// �� ����� ������ Atlas �˻�
}

void SpriteAtlasSample::Render()
{
	NNScene::Render();
}

void SpriteAtlasSample::Update( float dTime )
{
	NNScene::Update(dTime);
}