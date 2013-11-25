
#pragma once

#include "NNConfig.h"
#include "NNSound.h"
#include "Library/FMOD/inc/fmod.hpp"
#include "Library/FMOD/inc/fmod_errors.h"

/* */
/* NNAudioSystem
/* 사운드 출력을 담당하는 싱글톤 클래스
/* FMOD 라이브러리를 사용하고있다.
/* */

class NNAudioSystem
{
public:
	static NNAudioSystem* GetInstance();
	/* 싱글톤 인스턴트를 반환하는 함수 */
	static void ReleaseInstance();
	/* 싱글톤 인스턴트를 해제하는 함수 */

	void Play( NNSound* sound );
	/* 사운드를 재생하는 함수 */
	void Pause( NNSound* sound );
	/* 사운드를 일시정지하는 함수 */
	void Stop( NNSound* sound );
	/* 사운드를 정지하는 함수 */
	void Reset( NNSound* sound );
	/* 사운드를 시작지점으로 이동하는 함수 */

	void SetVolume( NNSound* sound, float volume );
	/* 사운드 볼륨을 조절하는 함수 */
	void SetPan( NNSound* sound, float pan );
	/* 사운드가 들리는 방향을 정하는 함수 */
	void SetFrequency( NNSound* sound, float frequency );
	/* 사운드의 주파수를 조절하는 함수 */

	bool IsPlay( NNSound* sound );
	/* 현재 사운드가 재생되고 있는지 판별하는 함수 */

	FMOD::System* GetSystem() { return m_System; }
	/* FMOD 라이브러리의 System변수를 반환하는 함수 */

private:
	FMOD::System* m_System;
	/* FMOD 라이브러리의 System */
	FMOD::ChannelGroup* m_ChannelGroup;
	/* FMOD 라이브러리의 ChannelGroup */

	static NNAudioSystem* m_pInstance;
	/* NNAudioSystem의 싱글톤 인스턴스 */

	NNAudioSystem();
	/* 생성자 */
	~NNAudioSystem();
	/* 소멸자 */
};