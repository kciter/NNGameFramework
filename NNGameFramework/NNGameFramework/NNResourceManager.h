
#pragma once

#include "NNConfig.h"
#include "NNTexture.h"

/* */
/* NNResourceManager
/* 파일 리소스를 관리하는 싱글톤 클래스
/* 현재 텍스쳐 파일만 관리함
/* */

class NNResourceManager
{
private:
	static NNResourceManager* m_pInstance;

private:
	std::map<std::wstring,NNTexture*> m_TextureTable;

private:
	NNResourceManager();
	~NNResourceManager();

public:
	static NNResourceManager* GetInstance();
	static void ReleaseInstance();

	//NNTexture* LoadTexture( std::string key );
	NNTexture* LoadTextureFromFile( std::wstring path );
};


