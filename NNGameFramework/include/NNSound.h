
/**
 * NNSound.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

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

	FMOD::Sound* GetSound() { return mSound; }
	FMOD::Sound** GetSoundPointer() { return &mSound; }
	FMOD::Channel* GetChannel() { return mChannel; }
	FMOD::Channel** GetChannelPointer() { return &mChannel; }

public:
	FMOD::Sound* mSound;
	FMOD::Channel* mChannel;
};

/*
class NNSound
{
private:
	MCIDEVICEID mMciDevice;

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
	bool mPlaying;

public:
	inline bool IsPlaying() { return mPlaying; }
};
*/