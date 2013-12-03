
#pragma once

#include "NNScene.h"
#include "NNAnimation.h"

class AnimationSample : public NNScene
{
public:
	AnimationSample();
	virtual ~AnimationSample();

	void Init();
	void Render();
	void Update( float eTime );

	NNCREATE_FUNC(AnimationSample);

private:
	NNAnimation* m_Animation;
};