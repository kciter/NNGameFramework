
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
	static NNApplication* m_pInstance;
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
	NNRenderer* m_Renderer;
	/* ������ �������̽� */
	NNSceneDirector* m_pSceneDirector;
	/* ���� �����ϴ� �����͸� �����ͷ� �޾ƿ´� */

private:
	HWND m_Hwnd;
	/* ���α׷� �ڵ� */
	HINSTANCE m_hInstance;
	/* ���α׷� �ڵ� �޸��� �ڵ� */
	RendererStatus m_RendererStatus;
	/* ���� �������� ����(����) */

private:
	wchar_t* m_Title;
	/* ���α׷��� �̸� */
	int m_ScreenWidth;
	/* ������ �������� �ʺ� */
	int m_ScreenHeight;
	/* ������ �������� ���� */

private:
	float m_Fps;
	/* ���� ������ Frame Per Second, �ʴ� ������ �� */
	float m_FpsTimer;
	/* �� ������ ���� �ֱ�� �������� �����Ѵ� */
	float m_ElapsedTime;
	/* ���α׷��� ���۵� �� ���� �ð� */
	float m_DeltaTime;
	/* ���� �����Ӱ� ���� �������� �ð� �� */

	int m_PrevTime;
	/* �����Ӱ� DeltaTime�� ���ϱ� ���� ���� */
	int m_NowTime;
	/* �����Ӱ� DeltaTime�� ���ϱ� ���� ���� */
	int m_FrameCount;
	/* ������ ī��Ʈ */

	bool m_DestroyWindow;
	/* �����찡 ��������� Ȯ���ϴ� ���� */

private:
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
	/* ������ �޼��� ť ó�� �ݹ� �Լ� */

public:
	inline NNRenderer* GetRenderer() const { return m_Renderer; }
	/* ���� ������ ���¸� ��ȯ�ϴ� �Լ� */
	inline HWND GetHWND() const { return m_Hwnd; }
	/* ���α׷� �ڵ��� ��ȯ�ϴ� �Լ� */
	inline HINSTANCE GetHandleInstance() const { return m_hInstance; }
	/* ���α׷� �ڵ� �޸��� �ڵ��� ��ȯ�ϴ� �Լ� */
	inline const wchar_t* GetTitle() const { return m_Title; }
	/* Ÿ��Ʋ �̸��� ��ȯ�ϴ� �Լ� */
	inline int GetScreenWidth() const { return m_ScreenWidth; }
	/* ������ �������� �ʺ� ��ȯ�ϴ� �Լ� */
	inline int GetScreenHeight() const { return m_ScreenHeight; }
	/* ������ �������� ���̸� ��ȯ�ϴ� �Լ� */
	inline RendererStatus GetRendererStatus() const { return m_RendererStatus; }

	inline float GetFPS() const { return m_Fps; }
	/* ���� FPS�� ��ȯ�ϴ� �Լ� */
	inline float GetElapsedTime() const { return m_ElapsedTime; }
	/* ���α׷��� ���۵� �� ���� �ð��� ��ȯ�ϴ� �Լ� */
	inline float GetDeltaTime() const { return m_DeltaTime; }
	/* ���� �����Ӱ� ���� �������� �ð� ���� ��ȯ�ϴ� �Լ� */
};

