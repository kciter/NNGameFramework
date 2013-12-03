
#include "Player.h"

Player::Player()
{
}
Player::~Player()
{

}

void Player::Init()
{
	m_Move = NNAnimation::Create( 2, L"Resources/Texture/walk_0.png", L"Resources/Texture/walk_1.png" );

	AddChild( m_Move );
}

void Player::Render()
{
	NNObject::Render();
}
void Player::Update( float dTime )
{
	NNObject::Update( dTime );
}