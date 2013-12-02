
#include "ParticleSample.h"
#include "NNApplication.h"
#include "NNInputSystem.h"

ParticleSample::ParticleSample()
{
	m_ParticleSystem1 = NNParticleSystem::Create(L"Resources/Texture/character.png");
	AddChild( m_ParticleSystem1 );
	m_ParticleSystem2 = NNParticleSystem::Create(L"Resources/Texture/fire.jpg");
	AddChild( m_ParticleSystem2 );
	m_ParticleSystem3 = NNParticleSystem::Create(L"Resources/Texture/walk_0.png");
	AddChild( m_ParticleSystem3 );
// 
  	m_ParticleSystem1->SetPosition( NNApplication::GetInstance()->GetScreenWidth()/2.f, NNApplication::GetInstance()->GetScreenHeight()/2.f );
  	m_ParticleSystem1->SetMaxLifeTime(1.f);
	m_ParticleSystem1->SetDirection(-90.f);
 	m_ParticleSystem1->SetSpreadDegree(90.f);

	m_ParticleSystem2->SetPosition( NNApplication::GetInstance()->GetScreenWidth()/2.f, NNApplication::GetInstance()->GetScreenHeight()/2.f );
	m_ParticleSystem2->SetMinStartRodiusX( 100.f );
	m_ParticleSystem2->SetMinStartRodiusY( 100.f );
	m_ParticleSystem2->SetMaxStartRodiusX( 100.f );
	m_ParticleSystem2->SetMaxStartRodiusY( 100.f );
	m_ParticleSystem2->SetMinStartSpeed( 10.f );
	m_ParticleSystem2->SetMaxStartSpeed( 10.f );
	m_ParticleSystem2->SetSpreadDegree( 360.f );
	m_ParticleSystem2->SetSystemLifeTime(2.f);

	m_ParticleSystem3->SetPosition( NNApplication::GetInstance()->GetScreenWidth()/2.f, NNApplication::GetInstance()->GetScreenHeight()/2.f );

	m_ParticleSystem1->SetVisible(false);
	m_ParticleSystem2->SetVisible(true);
	m_ParticleSystem3->SetVisible(false);

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

	if ( NNInputSystem::GetInstance()->GetKeyState('1') == KEY_DOWN )
	{
		m_ParticleSystem1->SetVisible(true);
		m_ParticleSystem2->SetVisible(false);
		m_ParticleSystem3->SetVisible(false);
	}
	else if ( NNInputSystem::GetInstance()->GetKeyState('2') == KEY_DOWN )
	{
		m_ParticleSystem1->SetVisible(false);
		m_ParticleSystem2->SetVisible(true);
		m_ParticleSystem3->SetVisible(false);
	}
	else if ( NNInputSystem::GetInstance()->GetKeyState('3') == KEY_DOWN )
	{
		m_ParticleSystem1->SetVisible(false);
		m_ParticleSystem2->SetVisible(false);
		m_ParticleSystem3->SetVisible(true);
	}
	else if ( NNInputSystem::GetInstance()->GetKeyState('4') == KEY_DOWN )
	{

	}
} 