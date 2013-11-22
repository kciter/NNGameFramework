
#pragma once

#include "NNConfig.h"
#include "NNTexture.h"
#include "NNXML.h"
#include "NNSound.h"

/* */
/* NNResourceManager
/* ���� ���ҽ��� �����ϴ� �̱��� Ŭ����
/* ���� �ؽ��� ���ϸ� ������
/* */

class NNResourceManager
{
private:
	static NNResourceManager* m_pInstance;

private:
	std::map<std::wstring,NNTexture*> m_TextureTable;
	std::map<std::string,NNXML*> m_XMLTable;
	std::map<std::string,NNSound*> m_SoundTable;
private:
	NNResourceManager();
	~NNResourceManager();

public:
	static NNResourceManager* GetInstance();
	static void ReleaseInstance();

	//NNTexture* LoadTexture( std::string key );
	NNTexture* LoadTextureFromFile( std::wstring path );
	NNXML* LoadXMLFromFIle( std::string path );
	NNSound* LoadSoundFromFile( std::string path, bool isLoop=false, bool isBackground=false );
	NNXML* LoadXmlFromZip ( std::string zipPath, std::string xmlName);
};


