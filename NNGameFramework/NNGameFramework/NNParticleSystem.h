
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

	static NNParticleSystem* Create( std::wstring path );

public:
	bool IsCreate() const { return m_IsCreate; }
	int GetCount() const { return m_ParticleList.size(); }
	int GetCreateParticlePerSecond() const { return m_CreateParticlePerSecond; }

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

	float GetMinEndScaleX() const { return m_MinEndScaleX; }
	float GetMaxEndScaleX() const { return m_MaxEndScaleX; }

	float GetMinEndScaleY() const { return m_MinEndScaleY; }
	float GetMaxEndScaleY() const { return m_MaxEndScaleY; }

	float GetDirection() const { return m_Direction; }

	float GetSpreadDegree() const { return m_SpreadDegree; }

	float GetMinStartRodiusX() const { return m_MinStartRadiusX; }
	float GetMaxStartRodiusX() const { return m_MaxStartRadiusX; }

	float GetMinStartRodiusY() const { return m_MinStartRadiusY; }
	float GetMaxStartRodiusY() const { return m_MaxStartRadiusY; }

	NNColor GetMinStartColor() { return m_MinStartColor; }
	NNColor GetMaxStartColor() { return m_MaxStartColor; }

	NNColor GetMinEndColor() { return m_MinEndColor; }
	NNColor GetMaxEndColor() { return m_MaxEndColor; }

	void SetCreate( bool isCreate ) { m_IsCreate = isCreate; }

	void SetCreateParticlePerSecond( int createParticlePerSecond ) {  m_CreateParticlePerSecond = createParticlePerSecond; }

	void SetMinLifeTime( float minLifeTime ) { m_MinLifeTime = minLifeTime; }
	void SetMaxLifeTime( float maxLifeTime ) { m_MaxLifeTime = maxLifeTime; }

	void SetMinStartSpeed( float minStartSpeed ) { m_MinStartSpeed = minStartSpeed; }
	void SetMaxStartSpeed( float maxStartSpeed ) { m_MaxStartSpeed = maxStartSpeed; }

	void SetMinEndSpeed( float  minEndSpeed ) { m_MinEndSpeed = minEndSpeed; }
	void SetMaxEndSpeed( float maxEndSpeed ) { m_MaxEndSpeed = maxEndSpeed; }

	void SetMinStartRotationSpeed( float minStartRotationSpeed ) { m_MinStartRotationSpeed = minStartRotationSpeed; }
	void SetMaxStartRotationSpeed( float maxStartRotationSpeed ) { m_MaxStartRotationSpeed = maxStartRotationSpeed; }

	void SetMinEndRotationSpeed( float minEndRotationSpeed ) { m_MinEndRotationSpeed = minEndRotationSpeed; }
	void SetMaxEndRotationSpeed( float maxEndRotationSpeed ) { m_MaxEndRotationSpeed = maxEndRotationSpeed; }

	void SetMinStartScaleX( float minStartScaleX ) { m_MinStartScaleX = minStartScaleX; }
	void SetMaxStartScaleX( float maxStartScaleX) { m_MaxStartScaleX = maxStartScaleX; }

	void SetMinStartScaleY( float minStartScaleY ) { m_MinStartScaleY = minStartScaleY; }
	void SetMaxStartScaleY( float maxStartScaleY) { m_MaxStartScaleY = maxStartScaleY; }

	void SetMinEndSacleX( float minEndScaleX ) { m_MinEndScaleX = minEndScaleX; }
	void SetMaxEndSacleX( float maxEndScaleX ) { m_MaxEndScaleX = maxEndScaleX; }

	void SetMinEndSacleY( float minEndScaleY ) { m_MinEndScaleY = minEndScaleY; }
	void SetMaxEndSacleY( float maxEndScaleY) { m_MaxEndScaleY = maxEndScaleY; }

	void SetDirection( float direction ) { m_Direction = direction; }

	void SetSpreadDegree( float spreadDegree ) { m_SpreadDegree = spreadDegree; }

	void SetMinStartRodiusX( float minStartRadiusX ) { m_MinStartRadiusX = minStartRadiusX; }
	void SetMaxStartRodiusX( float mxStartRadiusX ) { m_MaxStartRadiusX = mxStartRadiusX ; }

	void SetMinStartRodiusY( float minStartRadiusY ) { m_MinStartRadiusY = minStartRadiusY; }
	void SetMaxStartRodiusY( float maxStartRadiusY ) { m_MaxStartRadiusY = maxStartRadiusY; }

	void SetMinStartColor( NNColor startColor ) { m_MinStartColor = startColor; }
	void SetMaxStartColor( NNColor startColor ) { m_MaxStartColor = startColor; }

	void SetMinEndColor( NNColor endColor) { m_MinEndColor = endColor; }
	void SetMaxEndColor( NNColor endColor) { m_MaxEndColor = endColor; }

	void SetSystemLifeTime ( float lifeTime ) { m_SystemLifeTime = lifeTime; }
	float GetSystemLifeTime () { return m_SystemLifeTime; }

	bool isAlive() { return (m_SystemLifeTime!=0 && m_SystemLifeTime<=m_nowTime) ? false : true; }

private:
	void CreateParticle();

private:
	NNParticle** m_ParticlePool;
	std::list<NNParticle*> m_ParticleList;

	std::wstring m_TexturePath; //
	
	int m_PoolCount;

	bool m_IsCreate;

	int m_CreateParticlePerSecond;
	float m_Timer;
	
	float m_MinLifeTime, m_MaxLifeTime;

	float m_MinStartSpeed, m_MaxStartSpeed;
	float m_MinEndSpeed, m_MaxEndSpeed;

	float m_MinStartRotationSpeed, m_MaxStartRotationSpeed;
	float m_MinEndRotationSpeed, m_MaxEndRotationSpeed;

	float m_MinStartScaleX, m_MaxStartScaleX;
	float m_MinStartScaleY, m_MaxStartScaleY;
	float m_MinEndScaleX, m_MaxEndScaleX;
	float m_MinEndScaleY, m_MaxEndScaleY;

	float m_Direction;
	float m_SpreadDegree;

	float m_MinStartRadiusX, m_MaxStartRadiusX;
	float m_MinStartRadiusY, m_MaxStartRadiusY;

	float m_SystemLifeTime, m_nowTime;

	NNColor m_MinStartColor, m_MaxStartColor;
	NNColor m_MinEndColor, m_MaxEndColor;
};