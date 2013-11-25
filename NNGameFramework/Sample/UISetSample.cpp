
#include "UISetSample.h"
#include "NNInputSystem.h"

UISetSample::UISetSample()
{
	m_UI = UISet::Create();
	SetUISet( m_UI );

	m_Map = NNSprite::Create(L"Resources/Texture/map.png");
	AddChild( m_Map );
}
UISetSample::~UISetSample()
{

}

void UISetSample::Render()
{
	NNScene::Render();
}
void UISetSample::Update( float dTime )
{
	NNScene::Update( dTime );

	if ( NNInputSystem::GetInstance()->GetKeyState(VK_LEFT) == KEY_PRESSED )
	{
		GetCamera().SetPosition( GetCamera().GetPositionX()-100*dTime, GetCamera().GetPositionY() );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState(VK_RIGHT) == KEY_PRESSED )
	{
		GetCamera().SetPosition( GetCamera().GetPositionX()+100*dTime, GetCamera().GetPositionY() );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState(VK_UP) == KEY_PRESSED )
	{
		GetCamera().SetPosition( GetCamera().GetPositionX(), GetCamera().GetPositionY()-100*dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState(VK_DOWN) == KEY_PRESSED )
	{
		GetCamera().SetPosition( GetCamera().GetPositionX(), GetCamera().GetPositionY()+100*dTime );
	}
}