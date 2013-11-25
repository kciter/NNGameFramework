
#pragma once

#include "NNScene.h"
#include "NNSprite.h"
#include "UISet.h"

class UISetSample : public NNScene
{
public:
	UISetSample();
	virtual ~UISetSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(UISetSample);

private:
	NNSprite* m_Map;
	UISet* m_UI;
};