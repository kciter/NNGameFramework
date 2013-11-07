
#ifdef _DEBUG

#pragma once

#include "NNScene.h"
#include "NNParticle.h"

class ParticleSample : public NNScene
{
public:
	ParticleSample();
	virtual ~ParticleSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(ParticleSample);

private:
};

#endif