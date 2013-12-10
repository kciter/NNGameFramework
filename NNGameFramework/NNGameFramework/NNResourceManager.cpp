/**
 * NN
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 김지환
 * 수정일: 2013. 12. 10
 */


#include "NNResourceManager.h"

NNResourceManager* NNResourceManager::mpInstance = nullptr;

NNResourceManager::NNResourceManager()
{
}
NNResourceManager::~NNResourceManager()
{
	for (auto& iter=mTextureTable.begin(); iter!=mTextureTable.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	mTextureTable.clear();

	for (auto& iter=mXMLTable.begin(); iter!=mXMLTable.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	mXMLTable.clear();

	for (auto& iter=mSoundTable.begin(); iter!=mSoundTable.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	mXMLTable.clear();

	for (auto& iter=mZipTable.begin(); iter!=mZipTable.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	mZipTable.clear();
}

NNResourceManager* NNResourceManager::GetInstance()
{
	if( mpInstance == nullptr )
	{
		mpInstance = new NNResourceManager();
	}
	return mpInstance;
}
void NNResourceManager::ReleaseInstance()
{
	if( mpInstance != nullptr )
	{
		delete mpInstance;
		mpInstance = nullptr;
	}
}
NNTexture* NNResourceManager::LoadTextureFromFile( std::wstring path )
{
	if ( !mTextureTable[path] )
	{
		mTextureTable[path] = NNTexture::Create( path );
	}
	return mTextureTable[path];
}

NNXML* NNResourceManager::LoadXMLFromFIle( std::string path )
{
	if ( !mXMLTable[path] )
	{
		mXMLTable[path] = NNXML::Create( path );
	}
	return mXMLTable[path];
}

NNSound* NNResourceManager::LoadSoundFromFile( std::string path, bool isLoop, bool isBackground )
{
	if ( !mSoundTable[path] )
	{
		mSoundTable[path] = NNSound::Create( path, isLoop, isBackground );
	}
	return mSoundTable[path];
}

NNZip* NNResourceManager::UnzipFileToMemory( std::wstring zipPath, std::wstring FileName)
{
	if(! mZipTable[zipPath + FileName])
	{
		HZIP hz = OpenZip(zipPath.c_str(),0);
		ZIPENTRY ze;
		int index=0;

		FindZipItem(hz,FileName.c_str() ,true , &index , &ze);
		//add error handle code here
		char *buf = new char[ze.unc_size];
		UnzipItem(hz,index, buf, ze.unc_size);

		mZipTable[zipPath + FileName] = NNZip::Create(buf, ze.unc_size);

		SafeDelete(buf);
		CloseZip(hz);
	}	
	return mZipTable[zipPath + FileName];
}

void NNResourceManager::CreateZipCode( char *buf, int size, char *result)
{
	md5_state_t state;
	md5_byte_t digest[16];
	int di;

	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)buf, size);
	md5_finish(&state, digest);

	for (di = 0; di < 16; ++di)
		sprintf_s(result + di * 2, sizeof(result+di*2), "%02x", digest[di]);
}

NNXML* NNResourceManager::LoadXMLFromMemory( NNZip *buf )
{
	//char *result = CreateZipCode( buf->GetBuffer(), buf->GetSize());

	char result[34];
	CreateZipCode( buf->GetBuffer(), buf->GetSize(), result);

	if ( !mXMLTable[result] )
		mXMLTable[result] = NNXML::CreateStream( buf->GetBuffer() );

	return mXMLTable[result];
}

NNTexture* NNResourceManager::LoadTextureFromMemory( NNZip *buf )
{
	//char *code = CreateZipCode( buf->GetBuffer(), buf->GetSize());
	char code[34];

	CreateZipCode( buf->GetBuffer(), buf->GetSize(), code);

	std::wstring result = std::wstring(code, code + sizeof(char) * 32);

 	if ( !mTextureTable[result] )
 		mTextureTable[result] = NNTexture::CreateStream( buf->GetBuffer(), buf->GetSize() );
 
 	return mTextureTable[result];
}

NNSound* NNResourceManager::LoadSoundFromMemory( NNZip *buf, bool isLoop, bool isBackground )
{
	char result[34];
	CreateZipCode( buf->GetBuffer(), buf->GetSize(), result);

	if ( !mSoundTable[result] )
		mSoundTable[result] = NNSound::CreateStream( buf, isLoop, isBackground );

	return mSoundTable[result];
}