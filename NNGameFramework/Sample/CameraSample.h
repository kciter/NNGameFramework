
#pragma once

#include "NNScene.h"
#include "NNSprite.h"

class CameraSample : public NNScene
{
public:
	CameraSample();
	virtual ~CameraSample();

	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CameraSample);

private:
	NNSprite* m_Sprite;
};
