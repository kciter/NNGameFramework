
#include "FMODSoundSample.h"
#include "NNResourceManager.h"
#include "NNAudioSystem.h"

FMODSoundSample::FMODSoundSample()
{
}
FMODSoundSample::~FMODSoundSample()
{
}

void FMODSoundSample::Init()
{
	m_Sound = NNResourceManager::GetInstance()->LoadSoundFromFile( "Resources/Sound/effect1.mp3", true );
	// ���� ����. ������ ������

	NNAudioSystem::GetInstance()->Play( m_Sound ); // �÷���
}

void FMODSoundSample::Render()
{
	NNScene::Render();
}
void FMODSoundSample::Update( float dTime )
{
	NNScene::Update(dTime);
}
