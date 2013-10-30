
#include "NNInputSystem.h"
#include "NNApplication.h"
#include <windows.h>

NNInputSystem* NNInputSystem::m_pInstance = nullptr;

NNInputSystem::NNInputSystem()
{
	ZeroMemory( m_PrevKeyState, sizeof(m_PrevKeyState) );
	ZeroMemory( m_NowKeyState, sizeof(m_NowKeyState) );
}
NNInputSystem::~NNInputSystem()
{
}

NNInputSystem* NNInputSystem::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new NNInputSystem();
	}

	return m_pInstance;
}
void NNInputSystem::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void NNInputSystem::UpdateKeyState()
{
	for (int i=0; i<256; i++ )
	{
		m_PrevKeyState[i] = m_NowKeyState[i];

		if( ::GetKeyState(i) & 0x8000 )
		{
			m_NowKeyState[i] = true;
		}
		else
		{
			m_NowKeyState[i] = false;
		}
	}
}
KeyState NNInputSystem::GetKeyState( int key )
{
	if ( m_PrevKeyState[key] == false && m_NowKeyState[key] == true )
	{
		return KEY_DOWN;
	}
	else if ( m_PrevKeyState[key] == true && m_NowKeyState[key] == true )
	{
		return KEY_PRESSED;
	}
	else if ( m_PrevKeyState[key] == true && m_NowKeyState[key] == false )
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
