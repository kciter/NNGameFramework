
#pragma once

#include "NNScene.h"
#include "NNSprite.h"

class NetworkSample : public NNScene
{
public:
	NetworkSample();
	virtual ~NetworkSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(NetworkSample);
	
private:
	NNSprite* m_Sprite;
};