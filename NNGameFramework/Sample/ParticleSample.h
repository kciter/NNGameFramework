
#pragma once

#include "NNScene.h"
#include "NNParticleSystem.h"

class ParticleSample : public NNScene
{
public:
	ParticleSample();
	virtual ~ParticleSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(ParticleSample);

private:
	NNParticleSystem* m_ParticleSystem1;
	NNParticleSystem* m_ParticleSystem2;
	NNParticleSystem* m_ParticleSystem3;
};