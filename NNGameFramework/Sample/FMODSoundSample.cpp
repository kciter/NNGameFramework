
#include "FMODSoundSample.h"
#include "NNResourceManager.h"
#include "NNAudioSystem.h"

FMODSoundSample::FMODSoundSample()
{
	m_Sound = NNResourceManager::GetInstance()->LoadSoundFromFile( "Resources/Sound/effect1.mp3", true );
	// 사운드 생성. 끝나도 루프됨

	NNAudioSystem::GetInstance()->Play( m_Sound ); // 플레이
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
