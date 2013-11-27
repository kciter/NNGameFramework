
#pragma once

#include "NNRenderer.h"
#include "NNSceneDirector.h"
#include "NNConfig.h"

/* */
/* NNApplication
/* 프레임워크의 핵심 클래스
/* 렌더러와 윈도우 프레임을 생성하고
/* 게임 루프를 도는 역활을 한다.
/* */

class NNApplication
{
private:
	static NNApplication* m_pInstance;
	/* NNApplication의 싱글톤 인스턴스 */

private:
	NNApplication();
	/* 생성자 */
	~NNApplication();
	/* 소멸자 */

public:
	static NNApplication* GetInstance();
	/* 싱글톤 인스턴스를 반환하는 함수 */
	static void ReleaseInstance();
	/* 싱글톤 인스턴스를 메모리 해제하는 함수 */

public:
	bool Init( wchar_t* title, int width, int height, RendererStatus renderStatus );
	/* 창크기와 렌더러를 선택한 후 윈도우 프레임 생성. 
	   타이틀 이름은 title 파라메터에 따라 정해진다. */
	bool Release();
	/* NNApplication에 속하는 멤버변수의 메모리를 해제하는 함수 */
	bool Run();
	/* 게임 루프를 실행하는 함수 */

private:
	bool _CreateWindow( wchar_t* title, int width, int height );
	/* 윈도우 프레임을 생성하는 내부 함수 */
	bool _CreateRenderer( RendererStatus renderStatus );
	/* 렌더러를 생성하는 내부 함수 */

private:
	NNRenderer* m_Renderer;
	/* 렌더러 인터페이스 */
	NNSceneDirector* m_pSceneDirector;
	/* 씬을 관리하는 씬디렉터를 포인터로 받아온다 */

private:
	HWND m_Hwnd;
	/* 프로그램 핸들 */
	HINSTANCE m_hInstance;
	/* 프로그램 코드 메모리의 핸들 */
	RendererStatus m_RendererStatus;
	/* 현재 렌더러의 상태(종류) */

private:
	wchar_t* m_Title;
	/* 프로그램의 이름 */
	int m_ScreenWidth;
	/* 윈도우 프레임의 너비 */
	int m_ScreenHeight;
	/* 윈도우 프레임의 높이 */

private:
	float m_Fps;
	/* 게임 루프의 Frame Per Second, 초당 프레임 수 */
	float m_FpsTimer;
	/* 이 변수의 값을 주기로 프레임을 측정한다 */
	float m_ElapsedTime;
	/* 프로그램이 시작된 후 지난 시간 */
	float m_DeltaTime;
	/* 이전 프레임과 현재 프레임의 시간 차 */

	int m_PrevTime;
	/* 프레임과 DeltaTime을 구하기 위한 변수 */
	int m_NowTime;
	/* 프레임과 DeltaTime을 구하기 위한 변수 */
	int m_FrameCount;
	/* 프레임 카운트 */

	bool m_DestroyWindow;
	/* 윈도우가 삭제됬는지 확인하는 변수 */

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
	/* 윈도우 메세지 큐 처리 콜백 함수 */

public:
	inline NNRenderer* GetRenderer() const { return m_Renderer; }
	/* 현재 렌더러 상태를 반환하는 함수 */
	inline HWND GetHWND() const { return m_Hwnd; }
	/* 프로그램 핸들을 반환하는 함수 */
	inline HINSTANCE GetHandleInstance() const { return m_hInstance; }
	/* 프로그램 코드 메모리의 핸들을 반환하는 함수 */
	inline const wchar_t* GetTitle() const { return m_Title; }
	/* 타이틀 이름을 반환하는 함수 */
	inline int GetScreenWidth() const { return m_ScreenWidth; }
	/* 윈도우 프레임의 너비를 반환하는 함수 */
	inline int GetScreenHeight() const { return m_ScreenHeight; }
	/* 윈도우 프레임의 높이를 반환하는 함수 */
	inline RendererStatus GetRendererStatus() const { return m_RendererStatus; }

	inline float GetFPS() const { return m_Fps; }
	/* 현재 FPS를 반환하는 함수 */
	inline float GetElapsedTime() const { return m_ElapsedTime; }
	/* 프로그램이 시작된 후 지난 시간을 반환하는 함수 */
	inline float GetDeltaTime() const { return m_DeltaTime; }
	/* 이전 프레임과 현재 프레임의 시간 차를 반환하는 함수 */
};

