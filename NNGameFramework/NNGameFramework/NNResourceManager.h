
/**
 * NNResourceManager
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNConfig.h"
#include "NNTexture.h"
#include "NNXML.h"
#include "NNSound.h"
#include "NNZip.h"
#include "Library/zip/unzip.h"
#include "Library/MD5/md5.h"

/* */
/* NNResourceManager
/* 파일 리소스를 관리하는 싱글톤 클래스
/* 현재 텍스쳐 파일만 관리함
/* */

class NNResourceManager
{
private:
	static NNResourceManager* mpInstance;

private:
	std::map<std::wstring,NNTexture*> mTextureTable;
	std::map<std::string,NNXML*> mXMLTable;
	std::map<std::string,NNSound*> mSoundTable;
	std::map<std::wstring,NNZip*> mZipTable;
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

	NNZip* UnzipFileToMemory( std::wstring zipPath, std::wstring FileName );
	NNTexture* LoadTextureFromMemory( NNZip *buf );
	NNXML* LoadXMLFromMemory( NNZip *buf );
	NNSound* LoadSoundFromMemory( NNZip *buf, bool isLoop=false, bool isBackground=false );

protected:
	//char* CreateZipCode( char *buf ,int size);//, char *result );
	void CreateZipCode( char *buf ,int size, char *result );
};