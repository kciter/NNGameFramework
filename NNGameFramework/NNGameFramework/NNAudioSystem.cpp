
/**
 * NNAudioSystem.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNAudioSystem.h"

NNAudioSystem* NNAudioSystem::mpInstance = nullptr;

NNAudioSystem::NNAudioSystem()
	: mSystem(nullptr)
{
	FMOD::System_Create( &mSystem );
	mSystem->init( 32, FMOD_INIT_NORMAL, 0 );
	mSystem->createChannelGroup( "MasterChannelGroup", &mChannelGroup );
}
NNAudioSystem::~NNAudioSystem()
{
	mSystem->release();
}

NNAudioSystem* NNAudioSystem::GetInstance()
{
	if ( mpInstance == nullptr )
	{
		mpInstance = new NNAudioSystem();
	}
	return mpInstance;
}
void NNAudioSystem::ReleaseInstance()
{
	if ( mpInstance != nullptr )
	{
		delete mpInstance;
		mpInstance = nullptr;
	}
}

void NNAudioSystem::Play( NNSound* sound )
{
	mSystem->playSound( sound->GetSound(), mChannelGroup, false, sound->GetChannelPointer() );
}
void NNAudioSystem::Pause( NNSound* sound )
{
	sound->GetChannel()->setPaused( true );
}
void NNAudioSystem::Stop( NNSound* sound )
{
	sound->GetChannel()->setPosition( 0, FMOD_TIMEUNIT_MS );
	sound->GetChannel()->setPaused( true );
}
void NNAudioSystem::Reset( NNSound* sound )
{
	sound->GetChannel()->setPosition( 0, FMOD_TIMEUNIT_MS );
}

void NNAudioSystem::SetVolume( NNSound* sound, float volume )
{
	sound->GetChannel()->setVolume( volume );
}
void NNAudioSystem::SetPan( NNSound* sound, float pan )
{
	sound->GetChannel()->setPan( pan );
}
void NNAudioSystem::SetFrequency( NNSound* sound, float frequency )
{
	sound->GetChannel()->setFrequency( frequency );
}

bool NNAudioSystem::IsPlay( NNSound* sound )
{
	bool isPlay;
	sound->GetChannel()->isPlaying( &isPlay );
	return isPlay;
}