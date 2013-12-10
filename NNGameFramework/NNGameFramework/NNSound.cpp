
/**
 * NNSound.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNSound.h"
#include "NNApplication.h"
#include "NNAudioSystem.h"

NNSound::NNSound()
	: mChannel(nullptr), mSound(nullptr)
{

}
NNSound::~NNSound()
{
	mSound->release();
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
NNSound* NNSound::CreateStream( NNZip *buf, bool isLoop, bool isBackground )
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

	FMOD_CREATESOUNDEXINFO exinfo;

	ZeroMemory(&exinfo, sizeof(FMOD_CREATESOUNDEXINFO));
	exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
	exinfo.length = buf->GetSize();

	NNAudioSystem::GetInstance()->GetSystem()->createSound( buf->GetBuffer(), (isLoop) ? FMOD_LOOP_NORMAL | FMOD_2D | FMOD_HARDWARE | FMOD_OPENMEMORY : FMOD_DEFAULT | FMOD_OPENMEMORY, &exinfo, pInstance->GetSoundPointer() );

	return pInstance;
}