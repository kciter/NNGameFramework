
/**
 * NNApplication.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#pragma once

#include "NNRenderer.h"
#include "NNSceneDirector.h"
#include "NNConfig.h"

/* */
/* NNApplication
/* �����ӿ�ũ�� �ٽ� Ŭ����
/* �������� ������ �������� �����ϰ�
/* ���� ������ ���� ��Ȱ�� �Ѵ�.
/* */

class NNApplication
{
private:
	static NNApplication* mpInstance;
	/* NNApplication�� �̱��� �ν��Ͻ� */

private:
	NNApplication();
	/* ������ */
	~NNApplication();
	/* �Ҹ��� */

public:
	static NNApplication* GetInstance();
	/* �̱��� �ν��Ͻ��� ��ȯ�ϴ� �Լ� */
	static void ReleaseInstance();
	/* �̱��� �ν��Ͻ��� �޸� �����ϴ� �Լ� */

public:
	bool Init( wchar_t* title, int width, int height, RendererStatus renderStatus );
	/* âũ��� �������� ������ �� ������ ������ ����. 
	   Ÿ��Ʋ �̸��� title �Ķ���Ϳ� ���� ��������. */
	bool Release();
	/* NNApplication�� ���ϴ� ��������� �޸𸮸� �����ϴ� �Լ� */
	bool Run();
	/* ���� ������ �����ϴ� �Լ� */

private:
	bool _CreateWindow( wchar_t* title, int width, int height );
	/* ������ �������� �����ϴ� ���� �Լ� */
	bool _CreateRenderer( RendererStatus renderStatus );
	/* �������� �����ϴ� ���� �Լ� */

private:
	NNRenderer* mRenderer;
	/* ������ �������̽� */
	NNSceneDirector* mpSceneDirector;
	/* ���� �����ϴ� �����͸� �����ͷ� �޾ƿ´� */

private:
	HWND mHwnd;
	/* ���α׷� �ڵ� */
	HINSTANCE mhInstance;
	/* ���α׷� �ڵ� �޸��� �ڵ� */
	RendererStatus mRendererStatus;
	/* ���� �������� ����(����) */

private:
	wchar_t* mTitle;
	/* ���α׷��� �̸� */
	int mScreenWidth;
	/* ������ �������� �ʺ� */
	int mScreenHeight;
	/* ������ �������� ���� */

private:
	float mFps;
	/* ���� ������ Frame Per Second, �ʴ� ������ �� */
	float mFpsTimer;
	/* �� ������ ���� �ֱ�� �������� �����Ѵ� */
	float mElapsedTime;
	/* ���α׷��� ���۵� �� ���� �ð� */
	float mDeltaTime;
	/* ���� �����Ӱ� ���� �������� �ð� �� */

	int mPrevTime;
	/* �����Ӱ� DeltaTime�� ���ϱ� ���� ���� */
	int mNowTime;
	/* �����Ӱ� DeltaTime�� ���ϱ� ���� ���� */
	int mFrameCount;
	/* ������ ī��Ʈ */

	bool mDestroyWindow;
	/* �����찡 ��������� Ȯ���ϴ� ���� */

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
	/* ������ �޼��� ť ó�� �ݹ� �Լ� */

public:
	inline NNRenderer* GetRenderer() const { return mRenderer; }
	/* ���� ������ ���¸� ��ȯ�ϴ� �Լ� */
	inline HWND GetHWND() const { return mHwnd; }
	/* ���α׷� �ڵ��� ��ȯ�ϴ� �Լ� */
	inline HINSTANCE GetHandleInstance() const { return mhInstance; }
	/* ���α׷� �ڵ� �޸��� �ڵ��� ��ȯ�ϴ� �Լ� */
	inline const wchar_t* GetTitle() const { return mTitle; }
	/* Ÿ��Ʋ �̸��� ��ȯ�ϴ� �Լ� */
	inline int GetScreenWidth() const { return mScreenWidth; }
	/* ������ �������� �ʺ� ��ȯ�ϴ� �Լ� */
	inline int GetScreenHeight() const { return mScreenHeight; }
	/* ������ �������� ���̸� ��ȯ�ϴ� �Լ� */
	inline RendererStatus GetRendererStatus() const { return mRendererStatus; }

	inline float GetFPS() const { return mFps; }
	/* ���� FPS�� ��ȯ�ϴ� �Լ� */
	inline float GetElapsedTime() const { return mElapsedTime; }
	/* ���α׷��� ���۵� �� ���� �ð��� ��ȯ�ϴ� �Լ� */
	inline float GetDeltaTime() const { return mDeltaTime; }
	/* ���� �����Ӱ� ���� �������� �ð� ���� ��ȯ�ϴ� �Լ� */
};

