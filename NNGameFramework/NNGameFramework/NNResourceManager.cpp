
#include "NNResourceManager.h"
//#include "NNApplication.h"
#include <iostream>
NNResourceManager* NNResourceManager::m_pInstance = nullptr;

NNResourceManager::NNResourceManager()
{
}
NNResourceManager::~NNResourceManager()
{
	for (auto& iter=m_TextureTable.begin(); iter!=m_TextureTable.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	m_TextureTable.clear();

	for (auto& iter=m_XMLTable.begin(); iter!=m_XMLTable.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	m_XMLTable.clear();

	for (auto& iter=m_SoundTable.begin(); iter!=m_SoundTable.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	m_XMLTable.clear();

	for (auto& iter=m_ZipTable.begin(); iter!=m_ZipTable.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	m_ZipTable.clear();
}

NNResourceManager* NNResourceManager::GetInstance()
{
	if( m_pInstance == nullptr )
	{
		m_pInstance = new NNResourceManager();
	}
	return m_pInstance;
}
void NNResourceManager::ReleaseInstance()
{
	if( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
NNTexture* NNResourceManager::LoadTextureFromFile( std::wstring path )
{
	if ( !m_TextureTable[path] )
	{
		m_TextureTable[path] = NNTexture::Create( path );
	}
	return m_TextureTable[path];
}

NNXML* NNResourceManager::LoadXMLFromFIle( std::string path )
{
	if ( !m_XMLTable[path] )
	{
		m_XMLTable[path] = NNXML::Create( path );
	}
	return m_XMLTable[path];
}

NNSound* NNResourceManager::LoadSoundFromFile( std::string path, bool isLoop, bool isBackground )
{
	if ( !m_SoundTable[path] )
	{
		m_SoundTable[path] = NNSound::Create( path, isLoop, isBackground );
	}
	return m_SoundTable[path];
}

NNZip* NNResourceManager::UnzipFileToMemory( std::wstring zipPath, std::wstring FileName)
{
	if(! m_ZipTable[zipPath + FileName])
	{
		HZIP hz = OpenZip(zipPath.c_str(),0);
		ZIPENTRY ze;
		int index=0;

		FindZipItem(hz,FileName.c_str() ,true , &index , &ze);
		//add error handle code here
		char *buf = new char[ze.unc_size];
		UnzipItem(hz,index, buf, ze.unc_size);

		m_ZipTable[zipPath + FileName] = NNZip::Create(buf, ze.unc_size);

		SafeDelete(buf);
		CloseZip(hz);
	}	
	return m_ZipTable[zipPath + FileName];
}

// char* NNResourceManager::CreateZipCode( char *buf, int size)//, char *result)
// {
// 	md5_state_t state;
// 	md5_byte_t digest[16];
// 	char *result = new char[33];
// 	int di;
// 
// 	md5_init(&state);
// 	md5_append(&state, (const md5_byte_t *)buf, size);
// 	md5_finish(&state, digest);
// 
// 	for (di = 0; di < 16; ++di)
// 		sprintf(result + di * 2, "%02x", digest[di]);
// 
// 	//return nullptr;
// 	return result;
// }
void NNResourceManager::CreateZipCode( char *buf, int size, char *result)
{
	md5_state_t state;
	md5_byte_t digest[16];
	int di;

	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)buf, size);
	md5_finish(&state, digest);

	for (di = 0; di < 16; ++di)
		sprintf(result + di * 2, "%02x", digest[di]);
}
NNXML* NNResourceManager::LoadXMLFromMemory( NNZip *buf )
{
	//char *result = CreateZipCode( buf->GetBuffer(), buf->GetSize());

	char result[33];
	CreateZipCode( buf->GetBuffer(), buf->GetSize(), result);

	if ( !m_XMLTable[result] )
		m_XMLTable[result] = NNXML::CreateStream( buf->GetBuffer() );

	return m_XMLTable[result];
}
NNTexture* NNResourceManager::LoadTextureFromMemory( NNZip *buf )
{
	//char *code = CreateZipCode( buf->GetBuffer(), buf->GetSize());
	char code[33];

	CreateZipCode( buf->GetBuffer(), buf->GetSize(), code);

	std::wstring result = std::wstring(code, code + sizeof(char) * 32);

 	if ( !m_TextureTable[result] )
 		m_TextureTable[result] = NNTexture::CreateStream( buf->GetBuffer(), buf->GetSize() );
 
 	return m_TextureTable[result];
}
NNSound* NNResourceManager::LoadSoundFromMemory( NNZip *buf, bool isLoop, bool isBackground )
{
	//char *result = CreateZipCode( buf->GetBuffer(), buf->GetSize());
	//char result[33];
	char result[33];
	CreateZipCode( buf->GetBuffer(), buf->GetSize(), result);

	if ( !m_SoundTable[result] )
		m_SoundTable[result] = NNSound::CreateStream( buf, isLoop, isBackground );

	return m_SoundTable[result];
}