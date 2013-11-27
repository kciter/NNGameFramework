
#pragma once

#include "NNScene.h"
#include "NNZip.h"
#include "NNXML.h"

class ZipSample : public NNScene
{
public:
	ZipSample();
	virtual ~ZipSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(ZipSample);

private:
	NNXML *m_TestXML;
};