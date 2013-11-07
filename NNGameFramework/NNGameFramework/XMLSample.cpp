
#ifdef _DEBUG

#pragma once

#include "XMLSample.h"
#include "NNResourceManager.h"
#include <iostream>

XMLSample::XMLSample()
{
	m_TestXML = NNResourceManager::GetInstance()->LoadXMLFromFIle("Resource/XML/test2.xml");
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << "xml end" << std::endl;
}
XMLSample::~XMLSample()
{

}

void XMLSample::Render()
{
	NNScene::Render();
}
void XMLSample::Update( float dTime )
{
	NNScene::Update(dTime);
}

#endif