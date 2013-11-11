
#pragma once

#include "XMLSample.h"
#include "NNResourceManager.h"
#include <iostream>

XMLSample::XMLSample()
{
	m_TestXML = NNResourceManager::GetInstance()->LoadXMLFromFIle("Resources/XML/test2.xml");
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << "xml end" << std::endl;
	// 커맨드 창 확인
	// test2.xml에서 Welcome 엘리멘트 안에 있는 값이 출력됨
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