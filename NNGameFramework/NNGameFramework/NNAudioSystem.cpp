
#include "NNAudioSystem.h"

NNAudioSystem* NNAudioSystem::m_pInstance = nullptr;

NNAudioSystem::NNAudioSystem()
	: m_System(nullptr)
{
	FMOD::System_Create( &m_System );
	m_System->init( 32, FMOD_INIT_NORMAL, 0 );
}
NNAudioSystem::~NNAudioSystem()
{
	m_System->release();
}

NNAudioSystem* NNAudioSystem::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new NNAudioSystem();
	}
	return m_pInstance;
}
void NNAudioSystem::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void NNAudioSystem::Play( NNSound* sound )
{
	m_System->playSound( sound->GetSound(), m_ChannelGroup, false, sound->GetChannelPointer() );
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