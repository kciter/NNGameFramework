
#include "NNApplication.h"

#include "AnimationSample.h"
#include "XMLSample.h"
#include "SpriteAtlasSample.h"
#include "CameraSample.h"
#include "FMODSoundSample.h"

/*
void main()
{
	WinMain(0, 0, 0, 3);
}*/

//int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd )
int main()
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( );
#endif

	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"D2D Test", 800, 600, D2D );

	// NNSceneDirector::GetInstance()->ChangeScene( AnimationSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( XMLSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( SpriteAtlasSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( CameraSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( FMODSoundSample::Create() );

	Application->Run();
	Application->Release();

	return 0;
}