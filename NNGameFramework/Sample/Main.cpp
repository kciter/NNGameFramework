
#include "NNApplication.h"

#include "SpriteSample.h"
#include "AnimationSample.h"
#include "XMLSample.h"
#include "SpriteAtlasSample.h"
#include "CameraSample.h"
#include "FMODSoundSample.h"
#include "NetworkSample.h"

#ifdef _DEBUG
#pragma comment(lib, "NNGameFramework_DEBUG.lib")
#else
#pragma comment(lib, "NNGameFramework.lib")
#endif

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd )
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( );

	AllocConsole();
	FILE* console;
	freopen_s( &console, "CONOUT$", "wt", stdout );

	printf_s("Console Open \n");
#endif

	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"D2D Test", 800, 600, D2D );

	//NNSceneDirector::GetInstance()->ChangeScene( NetworkSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( SpriteSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( AnimationSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( XMLSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( SpriteAtlasSample::Create() );
	 NNSceneDirector::GetInstance()->ChangeScene( CameraSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( FMODSoundSample::Create() );

	Application->Run();
	Application->Release();

#ifdef _DEBUG
	FreeConsole();
#endif

	return 0;
}