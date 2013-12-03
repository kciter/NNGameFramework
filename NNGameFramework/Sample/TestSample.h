
#pragma once

#include "NNScene.h"
#include "NNSprite.h"

class TestSample : public NNScene
{
public:
	TestSample();
	virtual ~TestSample();

	void Init();
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(TestSample);

private:
	int m_SceneState;

	NNSprite* m_Sprite;
	NNSprite* m_Sprite2;
};