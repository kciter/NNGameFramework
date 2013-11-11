
#pragma once

#include "NNObject.h"
#include "NNParticle.h"
#include <list>

class NNParticleSystem : public NNObject
{
public:
	NNParticleSystem();
	virtual ~NNParticleSystem();

	void Render();
	void Update( float dTime );

	static NNParticleSystem* Create();

private:
	std::list<NNParticle*> m_ParticleList;
};