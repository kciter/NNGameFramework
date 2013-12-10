
/**
 * NNApplication.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNApplication.h"
#include "NNInputSystem.h"
#include "NNAudioSystem.h"
#include "NNResourceManager.h"
#include "NNNetworkSystem.h"

#include "NNRandom.h"

#include "NND2DRenderer.h"
#include "NND3DRenderer.h"

NNApplication* NNApplication::mpInstance = nullptr;

NNApplication::NNApplication()
	: mHwnd(nullptr), mhInstance(nullptr),
	mScreenHeight(0), mScreenWidth(0),
	mFps(0.f), mElapsedTime(0.f), mDeltaTime(0.f),mFpsTimer(0.f),
	mPrevTime(0), mNowTime(0),
	mRenderer(nullptr), mpSceneDirector(nullptr),
	mRendererStatus(UNKNOWN),mDestroyWindow(false)
{
}
NNApplication::~NNApplication()
{
	// Release();
}

NNApplication* NNApplication::GetInstance()
{
	if ( mpInstance == nullptr )
	{
		mpInstance = new NNApplication();
	}

	return mpInstance;
}
void NNApplication::ReleaseInstance()
{
	if ( mpInstance != nullptr )
	{
		delete mpInstance;
		mpInstance = nullptr;
	}
}

bool NNApplication::Init( wchar_t* title, int width, int height, RendererStatus renderStatus )
{
	mhInstance = GetModuleHandle(0);

	mTitle = title;
	mScreenWidth = width;
	mScreenHeight = height;
	mRendererStatus = renderStatus;

	_CreateWindow( mTitle, mScreenWidth, mScreenHeight );
	_CreateRenderer( renderStatus );

	mpSceneDirector = NNSceneDirector::GetInstance();

	mRenderer->Init();
	mpSceneDirector->Init();

	srand( (unsigned int)time(NULL) ) ;

	return true;
}

bool NNApplication::Release()
{
	if ( mDestroyWindow ) {
		ReleaseInstance();
		return true;
	}
	mpSceneDirector->Release();

	NNSceneDirector::ReleaseInstance();
	NNResourceManager::ReleaseInstance();
	NNInputSystem::ReleaseInstance();
	NNAudioSystem::ReleaseInstance();
	NNNetworkSystem::ReleaseInstance();

	NNRandom::ReleaseInstance();

	SafeDelete( mRenderer );
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
			mFrameCount++;
			mNowTime = timeGetTime();
			if ( mPrevTime == 0.f )
			{
				mPrevTime = mNowTime;
			}
			mDeltaTime = (static_cast<float>(mNowTime - mPrevTime)) / 1000.f;
			mElapsedTime += mDeltaTime;
			mFpsTimer += mDeltaTime;
			if(mFpsTimer > 0.1f)
			{
				mFps = ((float)mFrameCount) / mFpsTimer;
				mFrameCount = 0;
				mFpsTimer = 0.f;
			}
			mPrevTime = mNowTime;

			NNInputSystem::GetInstance()->UpdateKeyState();

			mpSceneDirector->UpdateScene( mDeltaTime );

			mRenderer->Begin();
			mRenderer->Clear();
			mpSceneDirector->RenderScene();
			mRenderer->End();

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
	wcex.hInstance = mhInstance;
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

	mHwnd = CreateWindow( L"NNApplication", title, style, CW_USEDEFAULT, CW_USEDEFAULT,
		wr.right-wr.left, wr.bottom-wr.top, NULL, NULL, mhInstance, NULL);

	ShowWindow( mHwnd, SW_SHOWNORMAL );

	return true;
}
bool NNApplication::_CreateRenderer( RendererStatus renderStatus )
{
	switch( renderStatus )
	{
	case D2D:
		{
			mRenderer = new NND2DRenderer();
			break;
		}
	case D3D:
		{
			mRenderer = new NND3DRenderer();
			break;
		}
	default:
		return false;
	}

	return true;
}


LRESULT CALLBACK NNApplication::WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch( message )
	{
	case WM_CREATE:
		{
			break;
		}
	case WM_DESTROY:
		{
			NNApplication::GetInstance()->Release();
			NNApplication::GetInstance()->mDestroyWindow = true;
			PostQuitMessage(0);
			break;
		}
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint( hWnd, &ps );
			EndPaint( hWnd, &ps );
			break;
		}

	case WM_SOCKET:
		{
			if (WSAGETSELECTERROR(lParam))
			{	
				MessageBox(hWnd,L"WSAGETSELECTERROR",	L"Error", MB_OK|MB_ICONERROR);
				SendMessage(hWnd,WM_DESTROY,NULL,NULL);
				break;
			}

			switch (WSAGETSELECTEVENT(lParam))
			{
			case FD_CONNECT:
				{
					/// NAGLE 끈다
					/// NAGLE Algorithm
					/// http://en.wikipedia.org/wiki/Nagle's_algorithm
					int opt = 1 ;
					::setsockopt(NNNetworkSystem::GetInstance()->mSocket, IPPROTO_TCP, TCP_NODELAY, (const char*)&opt, sizeof(int)) ;

					int nResult = WSAAsyncSelect(NNNetworkSystem::GetInstance()->mSocket, hWnd, WM_SOCKET, (FD_CLOSE|FD_READ|FD_WRITE) ) ;
					if (nResult)
					{
						assert(false) ;
						break;
					}
				}
				break ;

			case FD_READ:
				{
					char inBuf[4096] = {0, } ;

					int recvLen = recv(NNNetworkSystem::GetInstance()->mSocket, inBuf, 4096, 0) ;

					if ( !NNNetworkSystem::GetInstance()->mRecvBuffer.Write(inBuf, recvLen) )
					{
						/// 버퍼 꽉찼다. 
						assert(false) ;
					}

					NNNetworkSystem::GetInstance()->ProcessPacket() ;

				}
				break;

			case FD_WRITE:
				{
					/// 실제로 버퍼에 있는것들 꺼내서 보내기
					int size = NNNetworkSystem::GetInstance()->mSendBuffer.GetCurrentSize() ;
					if ( size > 0 )
					{
						char* data = new char[size] ;
						NNNetworkSystem::GetInstance()->mSendBuffer.Peek(data) ;

						int sent = send(NNNetworkSystem::GetInstance()->mSocket, data, size, 0) ;

						/// 다를수 있다
						if ( sent != size )
							OutputDebugStringA("sent != request\n") ;

						NNNetworkSystem::GetInstance()->mSendBuffer.Consume(sent) ;

						delete [] data ;
					}

				}
				break ;

			case FD_CLOSE:
				{
					MessageBox(hWnd, L"Server closed connection", L"Connection closed!", MB_ICONINFORMATION|MB_OK);
					closesocket(NNNetworkSystem::GetInstance()->mSocket);
					SendMessage(hWnd,WM_DESTROY,NULL,NULL);
				}
				break;
			}
		} 
		break ;
	}

	return(DefWindowProc(hWnd,message,wParam,lParam));
}