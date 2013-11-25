
#pragma once

#include "NNObject.h"

class NNUISet : public NNObject
{
public:
	NNUISet();
	virtual ~NNUISet();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(NNUISet);
};