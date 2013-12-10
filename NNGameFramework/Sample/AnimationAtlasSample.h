
#pragma once

#include "NNScene.h"
#include "NNAnimationAtlas.h"

class AnimationAtlasSample : public NNScene
{
public:
	AnimationAtlasSample();
	virtual ~AnimationAtlasSample();

	void Init();
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(AnimationAtlasSample);

private:
	NNAnimationAtlas* mAnimationAtlas;
};