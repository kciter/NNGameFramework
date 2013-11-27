
#pragma once

#include "NNScene.h"
class ZipSample : public NNScene
{
public:
	ZipSample();
	virtual ~ZipSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(ZipSample);

private:
};