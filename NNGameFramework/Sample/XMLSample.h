
#pragma once

#include "NNScene.h"
#include "NNXML.h"

class XMLSample : public NNScene
{
public:
	XMLSample();
	virtual ~XMLSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(XMLSample);

private:
	NNXML* m_TestXML;
};