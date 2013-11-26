
#include "ParticleSample.h"
#include "NNApplication.h"

ParticleSample::ParticleSample()
{
	m_ParticleSystem1 = NNParticleSystem::Create(L"Resources/Texture/fire.png");
	AddChild( m_ParticleSystem1 );
	/*m_ParticleSystem2 = NNParticleSystem::Create(L"Resources/Texture/walk_0.png");
	AddChild( m_ParticleSystem2 );
	m_ParticleSystem3 = NNParticleSystem::Create(L"Resources/Texture/walk_0.png");
	AddChild( m_ParticleSystem3 );*/
// 
  	m_ParticleSystem1->SetPosition( 300.f, 300.f );
  	m_ParticleSystem1->SetMaxLifeTime(1.f);
	m_ParticleSystem1->SetDirection(-90.f);
 	m_ParticleSystem1->SetSpreadDegree(90.f);
// 	m_ParticleSystem1->SetMinStartScaleX( 0.2f );
// 	m_ParticleSystem1->SetMaxStartScaleX( 0.2f );
// 	m_ParticleSystem1->SetMinStartScaleY( 0.2f );
// 	m_ParticleSystem1->SetMaxStartScaleY( 0.2f );
// 	m_ParticleSystem1->SetMinEndSacleX( 0.1f );
// 	m_ParticleSystem1->SetMaxEndSacleX( 0.1f );
// 	m_ParticleSystem1->SetMinEndSacleY( 0.1f );
// 	m_ParticleSystem1->SetMaxEndSacleY( 0.1f );
// 	m_ParticleSystem1->SetMinStartSpeed( 5.f );
// 	m_ParticleSystem1->SetMaxStartSpeed( 5.f );
// 	m_ParticleSystem1->SetMinEndSpeed( 0.2f );
// 	m_ParticleSystem1->SetMaxEndSpeed( 0.2f );
// 	m_ParticleSystem1->SetMinStartRotationSpeed( 0.f );
// 	m_ParticleSystem1->SetMaxStartRotationSpeed( 0.f );
// 	m_ParticleSystem1->SetMinEndRotationSpeed( 5.f );
// 	m_ParticleSystem1->SetMaxEndRotationSpeed( 10.f );
// 	m_ParticleSystem1->SetMinStartRodiusX( 0.f );
// 	m_ParticleSystem1->SetMinStartRodiusY( 0.f );
// 	m_ParticleSystem1->SetMaxStartRodiusX( 5.f );
// 	m_ParticleSystem1->SetMaxStartRodiusY( 5.f );

	//m_ParticleSystem2->SetPosition( 200.f, 100.f );
	//m_ParticleSystem3->SetPosition( 300.f, 100.f );
}

ParticleSample::~ParticleSample()
{

}

void ParticleSample::Render()
{
	NNScene::Render();
	printf( "%f\n", NNApplication::GetInstance()->GetFPS() );
	printf( "%d\n", m_ParticleSystem1->GetCount() );
}

void ParticleSample::Update( float dTime )
{
	NNScene::Update( dTime );
} 