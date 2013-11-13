
#include "NetworkSample.h"
#include "NNNetworkSystem.h"
#include "NNInputSystem.h"

NetworkSample::NetworkSample()
{
	GetCamera().SetCameraAnchor(MIDDLE_CENTER);
	m_LoginHandler = new LoginHandler;
	m_MoveBroadcastHandler = new MoveBroadcastHandler;

	NNNetworkSystem::GetInstance()->Init();
	NNNetworkSystem::GetInstance()->Connect("localhost",9001);
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_LOGIN, m_LoginHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_MOVE, m_MoveBroadcastHandler );

	m_LoginHandler->m_LoginRequestPacket.m_PlayerId = 1000 + rand() % 101;

	NNNetworkSystem::GetInstance()->Write( (const char*)&m_LoginHandler->m_LoginRequestPacket, m_LoginHandler->m_LoginRequestPacket.m_Size );

	m_Background = NNSprite::Create( L"Resources/Texture/background.jpg" );
	m_Sprite = NNSprite::Create( L"Resources/Texture/walk_0.png" );
	AddChild(m_Background);
	AddChild(m_Sprite);
	m_Background->SetPosition(-400.f,-300.f);
	m_Sprite->SetCenter(m_Sprite->GetPositionX()/2.f, m_Sprite->GetPositionY()/2.f);
}
NetworkSample::~NetworkSample()
{
}

void NetworkSample::Render()
{
	NNScene::Render();
}
void NetworkSample::Update( float dTime )
{
	NNScene::Update( dTime );
	/*
	if ( !m_PlayerMap[m_LoginHandler->m_LoginBroadcastResultPacket.m_PlayerId] && m_LoginHandler->m_LoginBroadcastResultPacket.m_PlayerId != -1 ) 
	{
		m_PlayerMap[m_LoginHandler->m_LoginBroadcastResultPacket.m_PlayerId] = NNSprite::Create( L"Resources/Texture/walk_0.png" );
		AddChild(m_PlayerMap[m_LoginHandler->m_LoginBroadcastResultPacket.m_PlayerId]);
	}*/

	if ( m_LoginHandler->m_LoginCheck == true ) 
	{
		/*
		if ( !m_PlayerMap[m_LoginHandler->m_LoginResultPacket.m_PlayerId] && m_LoginHandler->m_LoginResultPacket.m_PlayerId != -1 )
		{
			m_PlayerMap[m_LoginHandler->m_LoginResultPacket.m_PlayerId] = NNSprite::Create( L"Resources/Texture/walk_0.png" );
			AddChild(m_PlayerMap[m_LoginHandler->m_LoginResultPacket.m_PlayerId]);
		}
		if ( !m_PlayerMap[m_MoveBroadcastHandler->m_MoveBroadcastResultPacket.m_PlayerId] && m_MoveBroadcastHandler->m_MoveBroadcastResultPacket.m_PlayerId != -1)
		{
			m_PlayerMap[m_MoveBroadcastHandler->m_MoveBroadcastResultPacket.m_PlayerId] = NNSprite::Create( L"Resources/Texture/walk_0.png" );
			AddChild(m_PlayerMap[m_MoveBroadcastHandler->m_MoveBroadcastResultPacket.m_PlayerId]);
		}
		*/
		/*
		if (m_MoveBroadcastHandler->m_MoveBroadcastResultPacket.m_PlayerId != -1)
			m_PlayerMap[m_MoveBroadcastHandler->m_MoveBroadcastResultPacket.m_PlayerId]->SetPosition( m_MoveBroadcastHandler->m_MoveBroadcastResultPacket.m_PositionX, m_MoveBroadcastHandler->m_MoveBroadcastResultPacket.m_PositionY );
			*/
		m_Sprite->SetPosition( m_MoveBroadcastHandler->m_MoveBroadcastResultPacket.m_PositionX, m_MoveBroadcastHandler->m_MoveBroadcastResultPacket.m_PositionY );
		GetCamera().SetPosition(m_Sprite->GetPosition());
		if ( NNInputSystem::GetInstance()->GetKeyState('W') == KEY_PRESSED )
		{
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PlayerId = m_LoginHandler->m_LoginResultPacket.m_PlayerId;
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PositionX = m_Sprite->GetPositionX();
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PositionY = m_Sprite->GetPositionY();
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_Direction = 'W';
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_DeltaTime = dTime;
			NNNetworkSystem::GetInstance()->Write( (const char*)&m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket, m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_Size );
		}
		else if ( NNInputSystem::GetInstance()->GetKeyState('A') == KEY_PRESSED )
		{
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PlayerId = m_LoginHandler->m_LoginResultPacket.m_PlayerId;
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PositionX = m_Sprite->GetPositionX();
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PositionY = m_Sprite->GetPositionY();
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_Direction = 'A';
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_DeltaTime = dTime;
			NNNetworkSystem::GetInstance()->Write( (const char*)&m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket, m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_Size );
		}
		else if ( NNInputSystem::GetInstance()->GetKeyState('S') == KEY_PRESSED )
		{
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PlayerId = m_LoginHandler->m_LoginResultPacket.m_PlayerId;
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PositionX = m_Sprite->GetPositionX();
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PositionY = m_Sprite->GetPositionY();
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_Direction = 'S';
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_DeltaTime = dTime;
			NNNetworkSystem::GetInstance()->Write( (const char*)&m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket, m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_Size );
		}
		else if ( NNInputSystem::GetInstance()->GetKeyState('D') == KEY_PRESSED )
		{
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PlayerId = m_LoginHandler->m_LoginResultPacket.m_PlayerId;
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PositionX = m_Sprite->GetPositionX();
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_PositionY = m_Sprite->GetPositionY();
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_DeltaTime = dTime;
			m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_Direction = 'D';
			NNNetworkSystem::GetInstance()->Write( (const char*)&m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket, m_MoveBroadcastHandler->m_MoveBroadcastRequestPacket.m_Size );
		}
	}
}