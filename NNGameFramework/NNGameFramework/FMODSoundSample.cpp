
#ifdef _DEBUG

#include "FMODSoundSample.h"
#include "NNResourceManager.h"
#include "NNAudioSystem.h"

FMODSoundSample::FMODSoundSample()
{
	m_Sound = NNResourceManager::GetInstance()->LoadSoundFromFile( "Sound/effect1.mp3", true );

	NNAudioSystem::GetInstance()->Play( m_Sound );
}
FMODSoundSample::~FMODSoundSample()
{

}

void FMODSoundSample::Render()
{
	NNScene::Render();
}
void FMODSoundSample::Update( float dTime )
{
	NNScene::Update(dTime);

	
}

#endif