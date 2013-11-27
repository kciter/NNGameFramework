
#pragma once

#include "NNScene.h"
#include "NNZip.h"
#include "NNXML.h"
#include "NNSprite.h"
#include "NNSound.h"

class ZipSample : public NNScene
{
public:
	ZipSample();
	virtual ~ZipSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(ZipSample);

private:
	NNZip *m_loadZip;
	NNXML *m_TestXML;
	NNSprite *m_TestSprite;
	NNSound *m_TestSound;
};