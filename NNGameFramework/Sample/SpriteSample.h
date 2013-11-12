
#pragma once

#include "NNScene.h"
#include "NNSprite.h"


class SpriteSample : public NNScene
{
public:
	SpriteSample();
	virtual ~SpriteSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(SpriteSample);

private:
	NNSprite* m_Sprite;
};