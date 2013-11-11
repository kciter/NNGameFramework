
#pragma once

#include "NNScene.h"
#include "NNSpriteAtlas.h"

class SpriteAtlasSample : public NNScene
{
public:
	SpriteAtlasSample();
	virtual ~SpriteAtlasSample();

	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(SpriteAtlasSample);

private:
	NNSpriteAtlas* m_SpriteAtlas;
};