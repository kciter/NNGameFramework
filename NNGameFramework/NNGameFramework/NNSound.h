
#pragma once

#include "NNConfig.h"
#include <mmsystem.h>



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


