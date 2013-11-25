
#pragma once

#include "NNScene.h"

class UISetSample : public NNScene
{
public:
	UISetSample();
	virtual ~UISetSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(UISetSample);
};