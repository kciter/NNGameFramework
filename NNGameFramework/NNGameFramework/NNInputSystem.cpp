
/**
 * NNInputSystem.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNInputSystem.h"
#include "NNApplication.h"
#include <windows.h>

NNInputSystem* NNInputSystem::mpInstance = nullptr;

NNInputSystem::NNInputSystem()
{
	ZeroMemory( mPrevKeyState, sizeof(mPrevKeyState) );
	ZeroMemory( mNowKeyState, sizeof(mNowKeyState) );
}
NNInputSystem::~NNInputSystem()
{
}

NNInputSystem* NNInputSystem::GetInstance()
{
	if ( mpInstance == nullptr )
	{
		mpInstance = new NNInputSystem();
	}

	return mpInstance;
}
void NNInputSystem::ReleaseInstance()
{
	if ( mpInstance != nullptr )
	{
		delete mpInstance;
		mpInstance = nullptr;
	}
}

void NNInputSystem::UpdateKeyState()
{
	if ( GetFocus() == NULL ) return;

	for (int i=0; i<256; i++ )
	{
		mPrevKeyState[i] = mNowKeyState[i];

		if( ::GetKeyState(i) & 0x8000 )
		{
			mNowKeyState[i] = true;
		}
		else
		{
			mNowKeyState[i] = false;
		}
	}
}
KeyState NNInputSystem::GetKeyState( int key )
{
	if ( mPrevKeyState[key] == false && mNowKeyState[key] == true )
	{
		return KEY_DOWN;
	}
	else if ( mPrevKeyState[key] == true && mNowKeyState[key] == true )
	{
		return KEY_PRESSED;
	}
	else if ( mPrevKeyState[key] == true && mNowKeyState[key] == false )
	{
		return KEY_UP;
	}
	
	return KEY_NOTPRESSED;
}

NNPoint NNInputSystem::GetMousePosition()
{
	POINT pt;
	GetCursorPos( &pt );
	ScreenToClient( NNApplication::GetInstance()->GetHWND(), &pt );

	return NNPoint((float)pt.x,(float)pt.y);
}

bool NNInputSystem::IsPressedAnyKey()
{
	for (int i = 0; i < sizeof(mNowKeyState) / sizeof(bool); ++i)
	{
		if (mNowKeyState[i] == true)
			return true;
	}
	return false;
}
