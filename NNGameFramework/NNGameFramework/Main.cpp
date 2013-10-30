
#include "NNApplication.h"
#include "SpriteExampleScene.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd )
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(  );
#endif

	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"D2D Test", 800, 600, D2D );
	// NNSceneDirector::GetInstance()->ChangeScene( /* Insert Scene! */ );
	NNSceneDirector::GetInstance()->ChangeScene( SpriteExampleScene::Create() );
	Application->Run();
	NNApplication::GetInstance()->Release();

	return 0;
}