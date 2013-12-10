
/**
 * NNApplication.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

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
	static NNApplication* mpInstance;
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
	NNRenderer* mRenderer;
	/* 렌더러 인터페이스 */
	NNSceneDirector* mpSceneDirector;
	/* 씬을 관리하는 씬디렉터를 포인터로 받아온다 */

private:
	HWND mHwnd;
	/* 프로그램 핸들 */
	HINSTANCE mhInstance;
	/* 프로그램 코드 메모리의 핸들 */
	RendererStatus mRendererStatus;
	/* 현재 렌더러의 상태(종류) */

private:
	wchar_t* mTitle;
	/* 프로그램의 이름 */
	int mScreenWidth;
	/* 윈도우 프레임의 너비 */
	int mScreenHeight;
	/* 윈도우 프레임의 높이 */

private:
	float mFps;
	/* 게임 루프의 Frame Per Second, 초당 프레임 수 */
	float mFpsTimer;
	/* 이 변수의 값을 주기로 프레임을 측정한다 */
	float mElapsedTime;
	/* 프로그램이 시작된 후 지난 시간 */
	float mDeltaTime;
	/* 이전 프레임과 현재 프레임의 시간 차 */

	int mPrevTime;
	/* 프레임과 DeltaTime을 구하기 위한 변수 */
	int mNowTime;
	/* 프레임과 DeltaTime을 구하기 위한 변수 */
	int mFrameCount;
	/* 프레임 카운트 */

	bool mDestroyWindow;
	/* 윈도우가 삭제됬는지 확인하는 변수 */

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
	/* 윈도우 메세지 큐 처리 콜백 함수 */

public:
	inline NNRenderer* GetRenderer() const { return mRenderer; }
	/* 현재 렌더러 상태를 반환하는 함수 */
	inline HWND GetHWND() const { return mHwnd; }
	/* 프로그램 핸들을 반환하는 함수 */
	inline HINSTANCE GetHandleInstance() const { return mhInstance; }
	/* 프로그램 코드 메모리의 핸들을 반환하는 함수 */
	inline const wchar_t* GetTitle() const { return mTitle; }
	/* 타이틀 이름을 반환하는 함수 */
	inline int GetScreenWidth() const { return mScreenWidth; }
	/* 윈도우 프레임의 너비를 반환하는 함수 */
	inline int GetScreenHeight() const { return mScreenHeight; }
	/* 윈도우 프레임의 높이를 반환하는 함수 */
	inline RendererStatus GetRendererStatus() const { return mRendererStatus; }

	inline float GetFPS() const { return mFps; }
	/* 현재 FPS를 반환하는 함수 */
	inline float GetElapsedTime() const { return mElapsedTime; }
	/* 프로그램이 시작된 후 지난 시간을 반환하는 함수 */
	inline float GetDeltaTime() const { return mDeltaTime; }
	/* 이전 프레임과 현재 프레임의 시간 차를 반환하는 함수 */
};

