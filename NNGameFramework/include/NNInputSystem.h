
#pragma once

#include "NNConfig.h"
#include "NNPoint.h"

/* */
/* NNInputSystem
/* 키 입력을 담당하는 싱글톤 클래스
/* */

enum KeyState
{
	KEY_DOWN, // 키를 누른 직후
	KEY_PRESSED, // 키를 누르고 있을때
	KEY_UP, // 키를 누르다가 땠을때
	KEY_NOTPRESSED, // 키를 누르지 않았을때
};

class NNInputSystem
{
private:
	static NNInputSystem* m_pInstance;
	/* NNInputSystem의 싱글톤 클래스 */

private:
	NNInputSystem();
	/* 생성자 */
	~NNInputSystem();
	/* 소멸자 */

private:
	bool m_PrevKeyState[256];
	/* 한 프레임 전 키 상태 */
	bool m_NowKeyState[256];
	/* 현재 프레임의 키 상태 */

public:
	static NNInputSystem* GetInstance();
	/* 싱글톤 인스턴스를 반환 */
	static void ReleaseInstance();
	/* 싱글톤 인스턴스를 해제 */

public:
	void UpdateKeyState();
	/* 키 상태를 업데이트하는 함수 */
	KeyState GetKeyState( int key );
	/* 파라메터에 해당하는 키의 상태를 반환 */
	NNPoint GetMousePosition();
	/* 현재 마우스 위치를 클라이언트 위치  반환하는 함수 */
};


