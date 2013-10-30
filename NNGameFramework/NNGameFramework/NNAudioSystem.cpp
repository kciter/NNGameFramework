
#include "NNAudioSystem.h"



NNAudioSystem* NNAudioSystem::m_pInstance = nullptr;

NNAudioSystem::NNAudioSystem()
	: m_BackgroundSound(nullptr)
{
}
NNAudioSystem::~NNAudioSystem()
{
	SafeDelete( m_BackgroundSound );

	for (auto iter=m_EffectSoundTable.begin(); iter!=m_EffectSoundTable.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	m_EffectSoundTable.clear();
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

/*		Background	*/
void NNAudioSystem::SetBackgroundSound( std::wstring path )
{
	if ( m_BackgroundSound != nullptr )
	{
		SafeDelete( m_BackgroundSound );
	}
	m_BackgroundSound = new NNSound();
	m_BackgroundSound->Create( path );
}
void NNAudioSystem::PlayBackgroundSound()
{
	if ( m_BackgroundSound != nullptr )
	{
		m_BackgroundSound->Play();
	}
}
void NNAudioSystem::PauseBackgroundSound()
{
	if ( m_BackgroundSound != nullptr )
	{
		m_BackgroundSound->Pause();
	}
}
void NNAudioSystem::StopBackgroundSound()
{
	if ( m_BackgroundSound != nullptr )
	{
		m_BackgroundSound->Stop();
	}
}

/*		Effect		*/
void NNAudioSystem::AddEffectSound( std::string key, std::wstring path )
{
	if ( m_EffectSoundTable[key] )
	{
		SafeDelete( m_EffectSoundTable[key] );
	}
	m_EffectSoundTable[key] = new NNSound();
	m_EffectSoundTable[key]->Create( path );
}
void NNAudioSystem::RemoveEffectSound( std::string key )
{
	if ( m_EffectSoundTable[key] )
	{
		SafeDelete( m_EffectSoundTable[key] );
	}
}

void NNAudioSystem::PlayEffectSound( std::string key )
{
	if ( m_EffectSoundTable[key] )
	{
		m_EffectSoundTable[key]->Play();
	}
}
void NNAudioSystem::PauseEffectSound( std::string key )
{
	if ( m_EffectSoundTable[key] )
	{
		m_EffectSoundTable[key]->Pause();
	}
}
void NNAudioSystem::StopEffectSound( std::string key )
{
	if ( m_EffectSoundTable[key] )
	{
		m_EffectSoundTable[key]->Stop();
	}
}

void NNAudioSystem::AllPlayEffectSound()
{
	for (auto iter=m_EffectSoundTable.begin(); iter!=m_EffectSoundTable.end(); iter++ )
	{
		iter->second->Play();
	}
}
void NNAudioSystem::AllPauseEffectSound()
{
	for (auto iter=m_EffectSoundTable.begin(); iter!=m_EffectSoundTable.end(); iter++ )
	{
		iter->second->Pause();
	}
}
void NNAudioSystem::AllStopEffectSound()
{
	for (auto iter=m_EffectSoundTable.begin(); iter!=m_EffectSoundTable.end(); iter++ )
	{
		iter->second->Stop();
	}
}


