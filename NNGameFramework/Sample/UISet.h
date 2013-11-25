
#pragma once

#include "NNSprite.h"
#include "NNUISet.h"

class UISet : public NNUISet
{
public:
	UISet();
	virtual ~UISet();

	void Render();
	void Update( float dTime );

private:
	NNSprite m_UI;
};