
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

public:
	bool GetMinLifeTime() const { return m_MinLifeTime; }


private:
	void CreateParticle();

private:
	std::list<NNParticle*> m_ParticleList;

	bool m_IsCreate;

	int m_Count;
	int m_CreateNumber;
	
	float m_MinLifeTime, m_MaxLifeTime;

	float m_MinStartSpeed, m_MaxStartSpeed;
	float m_MinEndSpeed, m_MaxEndSpeed;

	float m_MinStartRotationSpeed, m_MaxStartRotationSpeed;
	float m_MinEndRotationSpeed, m_MaxEndRotationSpeed;

	float m_MinStartScaleX, m_MaxStartScaleX;
	float m_MinStartScaleY, m_MaxStartScaleY;
	float m_MinEndScaleX, m_MaxEndScaleX;
	float m_MinEndScaleY, m_MaxEndScaleY;

	float m_StartOpacity;
	float m_EndOpacity;

	float m_Direction;
	float m_SpreadDegree;

	float m_MinStartRadiusX, m_MaxStartRadiusX;
	float m_MinStartRadiusY, m_MaxStartRadiusY;

	NNColor m_StartColor;
	NNColor m_EndColor;
};