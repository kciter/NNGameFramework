
#pragma once
#include "ZipSample.h"
#include "NNResourceManager.h"
#include <iostream>

ZipSample::ZipSample()
{
	NNZip *t = NNResourceManager::GetInstance()->UnzipFileToMemory(L"Resources/Zip/test.zip", L"test.xml");
	m_TestXML = NNResourceManager::GetInstance()->LoadXMLFromMemory( t );

	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << "xml end" << std::endl;
}
ZipSample::~ZipSample()
{

}

void ZipSample::Render()
{
	NNScene::Render();
}
void ZipSample::Update( float dTime )
{
	NNScene::Update(dTime);
}