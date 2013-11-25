
#pragma once

#include "NNConfig.h"
#include "NNSound.h"
#include "Library/FMOD/inc/fmod.hpp"
#include "Library/FMOD/inc/fmod_errors.h"

/* */
/* NNAudioSystem
/* ���� ����� ����ϴ� �̱��� Ŭ����
/* FMOD ���̺귯���� ����ϰ��ִ�.
/* */

class NNAudioSystem
{
public:
	static NNAudioSystem* GetInstance();
	/* �̱��� �ν���Ʈ�� ��ȯ�ϴ� �Լ� */
	static void ReleaseInstance();
	/* �̱��� �ν���Ʈ�� �����ϴ� �Լ� */

	void Play( NNSound* sound );
	/* ���带 ����ϴ� �Լ� */
	void Pause( NNSound* sound );
	/* ���带 �Ͻ������ϴ� �Լ� */
	void Stop( NNSound* sound );
	/* ���带 �����ϴ� �Լ� */
	void Reset( NNSound* sound );
	/* ���带 ������������ �̵��ϴ� �Լ� */

	void SetVolume( NNSound* sound, float volume );
	/* ���� ������ �����ϴ� �Լ� */
	void SetPan( NNSound* sound, float pan );
	/* ���尡 �鸮�� ������ ���ϴ� �Լ� */
	void SetFrequency( NNSound* sound, float frequency );
	/* ������ ���ļ��� �����ϴ� �Լ� */

	bool IsPlay( NNSound* sound );
	/* ���� ���尡 ����ǰ� �ִ��� �Ǻ��ϴ� �Լ� */

	FMOD::System* GetSystem() { return m_System; }
	/* FMOD ���̺귯���� System������ ��ȯ�ϴ� �Լ� */

private:
	FMOD::System* m_System;
	/* FMOD ���̺귯���� System */
	FMOD::ChannelGroup* m_ChannelGroup;
	/* FMOD ���̺귯���� ChannelGroup */

	static NNAudioSystem* m_pInstance;
	/* NNAudioSystem�� �̱��� �ν��Ͻ� */

	NNAudioSystem();
	/* ������ */
	~NNAudioSystem();
	/* �Ҹ��� */
};