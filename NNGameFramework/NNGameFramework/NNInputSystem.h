
/**
 * NNInputSystem.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: ����ȯ
 * ���� ���� : �ƹ� Ű�� �Է����� �� �� ����� bool�� �������ִ� �Լ� ����
 * ������: 2014. 1. 13
 */

#pragma once

#include "NNConfig.h"
#include "NNPoint.h"

/* */
/* NNInputSystem
/* Ű �Է��� ����ϴ� �̱��� Ŭ����
/* */

enum KeyState
{
	KEY_DOWN, // Ű�� ���� ����
	KEY_PRESSED, // Ű�� ������ ������
	KEY_UP, // Ű�� �����ٰ� ������
	KEY_NOTPRESSED, // Ű�� ������ �ʾ�����
};

class NNInputSystem
{
private:
	static NNInputSystem* mpInstance;
	/* NNInputSystem�� �̱��� Ŭ���� */

private:
	NNInputSystem();
	/* ������ */
	~NNInputSystem();
	/* �Ҹ��� */

private:
	bool mPrevKeyState[256];
	/* �� ������ �� Ű ���� */
	bool mNowKeyState[256];
	/* ���� �������� Ű ���� */

public:
	static NNInputSystem* GetInstance();
	/* �̱��� �ν��Ͻ��� ��ȯ */
	static void ReleaseInstance();
	/* �̱��� �ν��Ͻ��� ���� */

public:
	void UpdateKeyState();
	/* Ű ���¸� ������Ʈ�ϴ� �Լ� */
	KeyState GetKeyState( int key );
	/* �Ķ���Ϳ� �ش��ϴ� Ű�� ���¸� ��ȯ */
	NNPoint GetMousePosition();
	/* ���� ���콺 ��ġ�� Ŭ���̾�Ʈ ��ġ  ��ȯ�ϴ� �Լ� */
	bool IsPressedAnyKey();
};


