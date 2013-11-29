
#pragma once
#include "ZipSample.h"
#include "NNResourceManager.h"
#include "NNAudioSystem.h"
#include <iostream>

ZipSample::ZipSample()
{
	m_loadZip = NNResourceManager::GetInstance()->UnzipFileToMemory(L"Resources/map.csm", L"map.xml");
	m_TestXML = NNResourceManager::GetInstance()->LoadXMLFromMemory( m_loadZip );
	/*
	m_loadZip = NNResourceManager::GetInstance()->UnzipFileToMemory(L"Resources/map.csm", L"test.png");
	m_TestSprite = NNSprite::Create( m_loadZip );

	m_loadZip = NNResourceManager::GetInstance()->UnzipFileToMemory(L"Resources/map.csm", L"test.mp3");
	m_TestSound = NNResourceManager::GetInstance()->LoadSoundFromMemory( m_loadZip, true );
	*/
	std::cout << m_TestXML->XPathToString("/map/tileInfo/t0-0/@isFull").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/map/tileInfo/t0-0/@isFull").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/map/tileInfo/t0-0/@isFull").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/map/tileInfo/t0-0/@isFull").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/map/tileInfo/t0-0/@isFull").c_str() << std::endl;
	std::cout << m_TestXML->XPathToString("/map/tileInfo/t0-0/@isFull").c_str() << std::endl;
	std::cout << "xml end" << std::endl;

	//AddChild( m_TestSprite );
	//NNAudioSystem::GetInstance()->Play( m_TestSound );
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