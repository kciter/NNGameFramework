
#include "NNParticleSystem.h"
#include "NNRandom.h"

NNParticleSystem::NNParticleSystem()
	: m_IsCreate(true), m_CreateParticlePerSecond(180),
	m_MinLifeTime(1.f), m_MaxLifeTime(1.f),
	m_MinStartSpeed(100.f), m_MaxStartSpeed(100.f),
	m_MinEndSpeed(200.f), m_MaxEndSpeed(200.f),
	m_MinStartRotationSpeed(30.f), m_MaxStartRotationSpeed(30.f),
	m_MinEndRotationSpeed(90.f), m_MaxEndRotationSpeed(90.f),
	m_MinStartScaleX(1.f), m_MaxStartScaleX(1.f),
	m_MinStartScaleY(1.f), m_MaxStartScaleY(1.f),
	m_MinEndScaleX(2.f), m_MaxEndScaleX(2.f),
	m_MinEndScaleY(2.f), m_MaxEndScaleY(2.f),
	m_Direction(0.f), m_SpreadDegree(360.f),
	m_MinStartRadiusX(0.f), m_MaxStartRadiusX(0.f),
	m_MinStartRadiusY(0.f), m_MaxStartRadiusY(0.f),
	m_MinStartColor(255,255,255,1.f), m_MaxStartColor(255,255,255,1.f),
	m_MinEndColor(0,0,0,0.f), m_MaxEndColor(0,0,0,0.f),
	m_Timer(0.f), m_PoolCount(0), m_ParticlePool(nullptr),
	m_nowTime(0.f), m_SystemLifeTime(0.f) // 0 = infinite
{
}

NNParticleSystem::~NNParticleSystem()
{
	for ( const auto& iter : m_ParticleList )
	{
		delete iter;
	}
	m_ParticleList.clear();
}

NNParticleSystem* NNParticleSystem::Create( std::wstring path )
{
	NNParticleSystem* pInstance = new NNParticleSystem();
	pInstance->m_TexturePath = path;

	return pInstance;
}

void NNParticleSystem::Render()
{
	NNObject::Render();

	for ( const auto& iter : m_ParticleList )
	{
		iter->Render();
	}
}

void NNParticleSystem::Update( float dTime )
{
	NNObject::Update( dTime );

	if ( m_IsCreate == true )
	{
		m_Timer += dTime;
		if ( m_Timer >= 1.f/m_CreateParticlePerSecond)
		{
			for (int i=0; i< 2*dTime*m_CreateParticlePerSecond/(m_MinLifeTime+m_MaxLifeTime); i++ )
			{
				CreateParticle();
			}
			m_Timer = 0.f;
		}
		if(m_SystemLifeTime != 0)
		{
			m_nowTime += dTime;

			if(m_nowTime >= m_SystemLifeTime)
			{
				return;
			}
		}
	}

	for (auto& iter=m_ParticleList.begin(); iter!=m_ParticleList.end(); iter++ )
	{
		(*iter)->Update( dTime );
		if ( (*iter)->GetNowLifeTime() > (*iter)->GetLifeTime() )
		{
			delete *iter;
			iter = m_ParticleList.erase( iter );
			if ( iter == m_ParticleList.end() )
			{
				break;
			}
		}
	}
}

void NNParticleSystem::CreateParticle()
{
	NNParticle* pInstance = NNParticle::Create( m_TexturePath );

	pInstance->SetParentMatrix( this->m_Matrix );
	
	float tempDirection = NNDegreeToRadian(NNRandom::NextFloat(m_Direction-m_SpreadDegree/2.f,m_Direction+m_SpreadDegree/2.f));
	pInstance->SetPosition(
		NNRandom::NextFloat(m_MinStartRadiusX, m_MaxStartRadiusX)*cos(tempDirection),
		NNRandom::NextFloat(m_MinStartRadiusX, m_MaxStartRadiusX)*sin(tempDirection) );

	pInstance->SetStartSpeed( NNRandom::NextFloat(m_MinStartSpeed, m_MaxStartSpeed) );
	pInstance->SetEndSpeed( NNRandom::NextFloat(m_MinEndSpeed, m_MaxEndSpeed) );

	pInstance->SetStartScaleX( NNRandom::NextFloat(m_MinStartScaleX, m_MaxStartScaleX) );
	pInstance->SetStartScaleY( NNRandom::NextFloat(m_MinStartScaleY, m_MaxStartScaleY) );
	pInstance->SetEndScaleX( NNRandom::NextFloat(m_MinEndScaleX, m_MaxEndScaleX) );
	pInstance->SetEndScaleY( NNRandom::NextFloat(m_MinEndScaleY, m_MaxEndScaleY) );

	pInstance->SetStartRotationSpeed( NNRandom::NextFloat(m_MinStartRotationSpeed, m_MaxStartRotationSpeed) );
	pInstance->SetEndRotationSpeed( NNRandom::NextFloat(m_MinEndRotationSpeed, m_MaxEndRotationSpeed) );

	pInstance->SetDirection( NNRandom::NextFloat(m_Direction-m_SpreadDegree/2.f, m_Direction+m_SpreadDegree/2.f) );

	pInstance->SetLifeTime( NNRandom::NextFloat(m_MinLifeTime, m_MaxLifeTime) );

	pInstance->SetStartRGBA( 
		NNRandom::NextInt(m_MinStartColor.GetRed(), m_MaxStartColor.GetRed()),
		NNRandom::NextInt(m_MinStartColor.GetGreen(), m_MaxStartColor.GetGreen()),
		NNRandom::NextInt(m_MinStartColor.GetBlue(), m_MaxStartColor.GetBlue()),
		NNRandom::NextInt(m_MinStartColor.GetAlpha(), m_MaxStartColor.GetAlpha()) );
	pInstance->SetEndRGBA( 
		NNRandom::NextInt(m_MinEndColor.GetRed(), m_MaxEndColor.GetRed()),
		NNRandom::NextInt(m_MinEndColor.GetGreen(), m_MaxEndColor.GetGreen()),
		NNRandom::NextInt(m_MinEndColor.GetBlue(), m_MaxEndColor.GetBlue()),
		NNRandom::NextInt(m_MinEndColor.GetAlpha(), m_MaxEndColor.GetAlpha()) );

	m_ParticleList.push_back( pInstance );
}