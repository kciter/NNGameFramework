
#pragma once

#include "NNConfig.h"
#include "NNSound.h"

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
private:
	static NNAudioSystem* m_pInstance;

private:
	NNAudioSystem();
	~NNAudioSystem();

public:
	static NNAudioSystem* GetInstance();
	static void ReleaseInstance();

private:
	NNSound* m_BackgroundSound;
	std::map<std::string, NNSound*> m_EffectSoundTable;

public:
	/*		Background	*/
	void SetBackgroundSound( std::wstring path );
	void PlayBackgroundSound();
	void PauseBackgroundSound();
	void StopBackgroundSound();

	/*		Effect		*/
	void AddEffectSound( std::string key, std::wstring path );
	void RemoveEffectSound( std::string key );

	void PlayEffectSound( std::string key );
	void PauseEffectSound( std::string key );
	void StopEffectSound( std::string key );

	void AllPlayEffectSound();
	void AllPauseEffectSound();
	void AllStopEffectSound();

public:
	inline NNSound* GetBackgroundSound() const { return m_BackgroundSound; }
	inline NNSound* GetEffectSound( std::string key ) /*const*/ { return m_EffectSoundTable[key]; }
};


