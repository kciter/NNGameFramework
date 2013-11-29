
#pragma once

#include "XMLSample.h"
#include "NNResourceManager.h"
#include <iostream>

XMLSample::XMLSample()
{
	m_TestXML = NNResourceManager::GetInstance()->LoadXMLFromFIle("Resources/XML/test2.xml");
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << "xml end" << std::endl;
	// Ŀ�ǵ� â Ȯ��
	// test2.xml���� Welcome ������Ʈ �ȿ� �ִ� ���� ��µ�
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