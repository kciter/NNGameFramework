
#pragma once

#include "NNConfig.h"
#include "NNZip.h"
#include "Library/FMOD/inc/fmod.hpp"
#include "Library/FMOD/inc/fmod_errors.h"

class NNSound
{
public:
	NNSound();
	~NNSound();

	static NNSound* Create( std::string path, bool isLoop=false, bool isBackground=false );
	static NNSound* CreateStream( NNZip* buf, bool isLoop=false, bool isBackground=false );

	FMOD::Sound* GetSound() { return m_Sound; }
	FMOD::Sound** GetSoundPointer() { return &m_Sound; }
	FMOD::Channel* GetChannel() { return m_Channel; }
	FMOD::Channel** GetChannelPointer() { return &m_Channel; }

public:
	FMOD::Sound* m_Sound;
	FMOD::Channel* m_Channel;
};

/*
class NNSound
{
private:
	MCIDEVICEID m_MciDevice;

public:
	NNSound();
	~NNSound();

	void Create( std::wstring path );
	void Destroy();

	void Play();
	void Pause();
	void Resume();
	void Stop();

private:
	bool m_Playing;

public:
	inline bool IsPlaying() { return m_Playing; }
};
*/