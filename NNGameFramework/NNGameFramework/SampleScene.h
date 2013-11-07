
#pragma once

#ifdef _DEBUG

#include "NNScene.h"

class SampleScene : public NNScene
{
public:
	SampleScene();
	virtual ~SampleScene();

	void Render();
	void Update( float eTime );

	NNCREATE_FUNC(SampleScene);
};

#endif