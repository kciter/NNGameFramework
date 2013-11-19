
#pragma once

#include "NNObject.h"

class ParticleSample : public NNObject
{
public:
	ParticleSample();
	virtual ~ParticleSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(ParticleSample);

private:
	//NNParticleSystem* m_ParticleSystem;
};