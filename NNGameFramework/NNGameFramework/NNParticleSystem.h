
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
	float GetMinLifeTime() const { return m_MinLifeTime; }
	float GetMaxLifeTime() const { return m_MaxLifeTime; }

	float GetMinStartSpeed() const { return m_MinStartSpeed; }
	float GetMaxStartSpeed() const { return m_MaxStartSpeed; }

	float GetMinEndSpeed() const { return m_MinEndSpeed; }
	float GetMaxEndSpeed() const { return m_MaxEndSpeed; }

	float GetMinStartRotationSpeed() const { return m_MinStartRotationSpeed; }
	float GetMaxStartRotationSpeed() const { return m_MaxStartRotationSpeed; }

	float GetMinEndRotationSpeed() const { return m_MinEndRotationSpeed; }
	float GetMaxEndRotationSpeed() const { return m_MaxEndRotationSpeed; }

	float GetMinStartScaleX() const { return m_MinStartScaleX; }
	float GetMaxStartScaleX() const { return m_MaxStartScaleX; }

	float GetMinStartScaleY() const { return m_MinStartScaleY; }
	float GetMaxStartScaleY() const { return m_MaxStartScaleY; }

	float GetMinEndSacleX() const { return m_MinEndScaleX; }
	float GetMaxEndSacleX() const { return m_MaxEndScaleX; }

	float GetMinEndSacleY() const { return m_MinEndScaleY; }
	float GetMaxEndSacleY() const { return m_MaxEndScaleY; }

	float GetStartOpacity() const { return m_StartOpacity; }
	float GetEndOpacity() const { return m_EndOpacity; }

	float GetDirection() const { return m_Direction; }

	float GetSpreadDegree() const { return m_SpreadDegree; }

	float GetMinStartRodiusX() const { return m_MinStartRadiusX; }
	float GetMaxStartRodiusX() const { return m_MaxStartRadiusX; }

	float GetMinStartRodiusY() const { return m_MinStartRadiusY; }
	float GetMaxStartRodiusY() const { return m_MaxStartRadiusY; }

	NNColor GetStartColor() { return m_StartColor; }
	NNColor GetEndColor() { return m_EndColor; }

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