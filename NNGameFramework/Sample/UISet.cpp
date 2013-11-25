
#include "UISet.h"

UISet::UISet()
{
	m_UI = NNSprite::Create(L"Resources/Texture/walk_0.png");
	AddChild( m_UI );
}
UISet::~UISet()
{

}

void UISet::Render()
{
	NNUISet::Render();
}
void UISet::Update( float dTime )
{
	NNUISet::Update( dTime );
}