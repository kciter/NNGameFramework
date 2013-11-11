
#include "NNApplication.h"
#include "NNInputSystem.h"
#include "NNAudioSystem.h"
#include "NNResourceManager.h"
//#include "NNNetworkSystem.h"

NNApplication* NNApplication::m_pInstance = nullptr;

NNApplication::NNApplication()
	: m_Hwnd(nullptr), m_hInstance(nullptr),
	m_ScreenHeight(0), m_ScreenWidth(0),
	m_Fps(0.f), m_ElapsedTime(0.f), m_DeltaTime(0.f),m_FpsTimer(0.f),
	m_PrevTime(0), m_NowTime(0),
	m_Renderer(nullptr), m_pSceneDirector(nullptr),
	m_RendererStatus(UNKNOWN),m_DestroyWindow(false)
{

}
NNApplication::~NNApplication()
{

}

NNApplication* NNApplication::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new NNApplication();
	}

	return m_pInstance;
}
void NNApplication::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

bool NNApplication::Init( wchar_t* title, int width, int height, RendererStatus renderStatus )
{
	m_hInstance = GetModuleHandle(0);

	m_Title = title;
	m_ScreenWidth = width;
	m_ScreenHeight = height;
	m_RendererStatus = renderStatus;

	_CreateWindow( m_Title, m_ScreenWidth, m_ScreenHeight );
	_CreateRenderer( renderStatus );

	m_pSceneDirector = NNSceneDirector::GetInstance();

	m_Renderer->Init();
	m_pSceneDirector->Init();

	return true;
}

bool NNApplication::Release()
{
	if ( m_DestroyWindow == true ) {
		ReleaseInstance();
		return true;
	}
	m_pSceneDirector->Release();

	NNSceneDirector::ReleaseInstance();
	NNResourceManager::ReleaseInstance();
	NNInputSystem::ReleaseInstance();
	NNAudioSystem::ReleaseInstance();
	//NNNetworkSystem::ReleaseInstance();
	SafeDelete( m_Renderer );
	ReleaseInstance();

	return true;
}

bool NNApplication::Run()
{
	MSG msg;
	ZeroMemory( &msg, sizeof(msg) );

	while (true)
	{
		if ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
		{
			if ( msg.message == WM_QUIT )
			{
				return true;
			}
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else{
			m_FrameCount++;
			m_NowTime = timeGetTime();
			if ( m_PrevTime == 0.f )
			{
				m_PrevTime = m_NowTime;
			}
			m_DeltaTime = (static_cast<float>(m_NowTime - m_PrevTime)) / 1000.f;
			m_ElapsedTime += m_DeltaTime;
			m_FpsTimer += m_DeltaTime;
			if(m_FpsTimer > 0.1f)
			{
				m_Fps = ((float)m_FrameCount) / m_FpsTimer;
				m_FrameCount = 0;
				m_FpsTimer = 0.f;
			}
			m_PrevTime = m_NowTime;

			NNInputSystem::GetInstance()->UpdateKeyState();

			m_pSceneDirector->UpdateScene( m_DeltaTime );

			m_Renderer->Begin();
			m_Renderer->Clear();
			m_pSceneDirector->RenderScene();
			m_Renderer->End();

			if ( NNInputSystem::GetInstance()->GetKeyState( VK_ESCAPE ) == KEY_DOWN )
			{
				PostQuitMessage(0);
			}
		}
	}

	return true;
}

bool NNApplication::_CreateWindow( wchar_t* title, int width, int height )
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = NULL;
	wcex.cbWndExtra = NULL;
	wcex.hInstance = m_hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"NNApplication";
	wcex.hIconSm = NULL;
	wcex.hIcon = NULL;

	RegisterClassEx( &wcex );

	DWORD style = WS_OVERLAPPEDWINDOW;

	RECT wr = {0, 0, width, height};
	AdjustWindowRect( &wr, WS_OVERLAPPEDWINDOW, FALSE );

	m_Hwnd = CreateWindow( L"NNApplication", title, style, CW_USEDEFAULT, CW_USEDEFAULT,
		wr.right-wr.left, wr.bottom-wr.top, NULL, NULL, m_hInstance, NULL);

	ShowWindow( m_Hwnd, SW_SHOWNORMAL );

	return true;
}
bool NNApplication::_CreateRenderer( RendererStatus renderStatus )
{
	switch( renderStatus )
	{
	case D2D:
		m_Renderer = new NND2DRenderer();
		break;
	default:
		return false;
	}

	return true;
}


LRESULT CALLBACK NNApplication::WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch( message )
	{
	case WM_DESTROY:
		NNApplication::GetInstance()->Release();
		NNApplication::GetInstance()->m_DestroyWindow = true;
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint( hWnd, &ps );
		EndPaint( hWnd, &ps );
	}

	return(DefWindowProc(hWnd,message,wParam,lParam));
}