
#pragma once

#include "NNScene.h"
#include "NNSprite.h"

class SpriteExampleScene : public NNScene
{
public:
	SpriteExampleScene();
	virtual ~SpriteExampleScene();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(SpriteExampleScene);

private:
	NNSprite* m_Sprite;
};