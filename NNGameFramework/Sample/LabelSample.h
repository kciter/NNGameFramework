
#pragma once

#include "NNScene.h"
#include "NNLabel.h"

class LabelSample : public NNScene
{
public:
	LabelSample();
	virtual ~LabelSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(LabelSample);
private:
	NNLabel* m_Label;
};