
#include "NNSound.h"
#include "NNApplication.h"
#include "NNAudioSystem.h"

NNSound::NNSound()
	: m_Channel(nullptr), m_Sound(nullptr)
{

}
NNSound::~NNSound()
{
	m_Sound->release();
}

NNSound* NNSound::Create( std::string path, bool isLoop, bool isBackground )
{
	NNSound* pInstance = new NNSound();

	/*if ( isBackground == true )
	{
		NNAudioSystem::GetInstance()->GetSystem()->createStream( path.c_str(), (isLoop) ? FMOD_LOOP_NORMAL | FMOD_2D | FMOD_HARDWARE : FMOD_DEFAULT, nullptr, pInstance->GetSoundPointer() );
	}
	else
	{
		NNAudioSystem::GetInstance()->GetSystem()->createSound( path.c_str(), (isLoop) ? FMOD_LOOP_NORMAL | FMOD_2D | FMOD_HARDWARE : FMOD_DEFAULT, nullptr, pInstance->GetSoundPointer() );
	}*/

	NNAudioSystem::GetInstance()->GetSystem()->createSound( path.c_str(), (isLoop) ? FMOD_LOOP_NORMAL | FMOD_2D | FMOD_HARDWARE : FMOD_DEFAULT, nullptr, pInstance->GetSoundPointer() );

	return pInstance;
}