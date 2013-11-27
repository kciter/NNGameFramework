
#include "NNResourceManager.h"
//#include "NNApplication.h"

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
	m_TextureTable.clear();

	for (auto& iter=m_SoundTable.begin(); iter!=m_SoundTable.end(); iter++ )
	{
		SafeDelete( iter->second );
	}
	m_TextureTable.clear();
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

char* NNResourceManager::UnzipFileToMemory( std::wstring zipPath, std::wstring FileName)
{
	HZIP hz = OpenZip(zipPath.c_str(),0);
	ZIPENTRY ze;
	int index=0;

	FindZipItem(hz,FileName.c_str() ,true , &index , &ze);
	char *buf = new char[ze.unc_size];
	UnzipItem(hz,index, buf, ze.unc_size);

	CloseZip(hz);

	return buf;
}

NNXML* NNResourceManager::LoadXMLFromMemory( char *buf )
{
// 	if ( !m_XMLTable[] )
//  	{
// 		m_XMLTable[path] = NNXML::Create( buf );
//  	}
// 	return m_XMLTable["AA"];
}
