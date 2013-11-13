
#pragma once

#include "NNObject.h"
#include "NNAnimation.h"

class Player : public NNObject
{
public:
	Player();
	virtual ~Player();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(Player);

private:
	NNAnimation* m_Move;
};