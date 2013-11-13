
#pragma once

#include "NNScene.h"
#include "Player.h"
#include "PacketHandler.h"

class NetworkSample : public NNScene
{
public:
	NetworkSample();
	virtual ~NetworkSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(NetworkSample);
	
private:
	NNSprite* m_Background;
	NNSprite* m_Sprite;
	int m_MyPlayerId;
	std::map<int,NNSprite*> m_PlayerMap;

	LoginHandler* m_LoginHandler;
	MoveBroadcastHandler* m_MoveBroadcastHandler;
};