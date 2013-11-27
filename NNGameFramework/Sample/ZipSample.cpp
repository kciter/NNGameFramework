
#pragma once
#include "ZipSample.h"
#include "NNResourceManager.h"
#include "NNAudioSystem.h"
#include <iostream>

ZipSample::ZipSample()
{
	m_loadZip = NNResourceManager::GetInstance()->UnzipFileToMemory(L"Resources/Zip/test.zip", L"test.xml");
	m_TestXML = NNResourceManager::GetInstance()->LoadXMLFromMemory( m_loadZip );

	m_loadZip = NNResourceManager::GetInstance()->UnzipFileToMemory(L"Resources/Zip/test.zip", L"test.png");
	m_TestSprite = NNSprite::Create( m_loadZip );

	m_loadZip = NNResourceManager::GetInstance()->UnzipFileToMemory(L"Resources/Zip/test.zip", L"test.mp3");
	m_TestSound = NNResourceManager::GetInstance()->LoadSoundFromMemory( m_loadZip, true );

	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << "xml end" << std::endl;

	AddChild( m_TestSprite );
	NNAudioSystem::GetInstance()->Play( m_TestSound );
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