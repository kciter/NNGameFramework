
#pragma once

#include "NNConfig.h"
#include "NNSound.h"
#include "Library/FMOD/inc/fmod.hpp"
#include "Library/FMOD/inc/fmod_errors.h"

/* */
/* NNAudioSystem
/* 사운드 출력을 담당하는 싱글톤 클래스/* */
/* Application
/* 프레임워크의 핵심 클래스
/* 렌더러와 윈도우 프레임을 생성하고
/* 게임 루프를 도는 역활을 한다.
/* */
/* */

class NNAudioSystem
{
public:
	static NNAudioSystem* GetInstance();
	static void ReleaseInstance();

	void Play( NNSound* sound );
	void Pause( NNSound* sound );
	void Stop( NNSound* sound );
	void Reset( NNSound* sound );

	void SetVolume( NNSound* sound, float volume );
	void SetPan( NNSound* sound, float pan );
	void SetFrequency( NNSound* sound, float frequency );

	bool IsPlay( NNSound* sound );

	FMOD::System* GetSystem() { return m_System; }

private:
	FMOD::System* m_System;
	FMOD::ChannelGroup* m_ChannelGroup;

	static NNAudioSystem* m_pInstance;

	NNAudioSystem();
	~NNAudioSystem();
};