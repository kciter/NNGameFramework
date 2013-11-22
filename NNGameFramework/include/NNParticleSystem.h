
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
	void CreateParticle();

private:
	std::list<NNParticle*> m_ParticleList;
	
	float m_LifeTime;
	float m_NowLifeTime;

	float m_StartSpeed;
	float m_EndSpeed;

	float m_StartRotationSpeed;
	float m_EndRotationSpeed;

	float m_StartScaleX, m_StartScaleY;
	float m_EndScaleX, m_EndScaleY;

	float m_StartOpacity;
	float m_EndOpacity;

	float m_Direction;
	float m_SpreadDegree;

	NNColor m_StartColor;
	NNColor m_EndColor;
};