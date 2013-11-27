
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

NNZip* NNResourceManager::UnzipFileToMemory( std::wstring zipPath, std::wstring FileName)
{
	HZIP hz = OpenZip(zipPath.c_str(),0);
	ZIPENTRY ze;
	int index=0;

	FindZipItem(hz,FileName.c_str() ,true , &index , &ze);
	char *buf = new char[ze.unc_size];
	UnzipItem(hz,index, buf, ze.unc_size);

	CloseZip(hz);

	m_ZipTable[zipPath] = NNZip::Create(buf, ze.unc_size);
	return m_ZipTable[zipPath];
}

NNXML* NNResourceManager::LoadXMLFromMemory( NNZip *buf )
{
	md5_state_t state;
	md5_byte_t digest[16];
	char result[16*2 + 1];
	int di;

	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)buf->GetBuffer(), buf->GetSize());
	md5_finish(&state, digest);

	for (di = 0; di < 16; ++di)
		sprintf(result + di * 2, "%02x", digest[di]);

	if ( !m_XMLTable[result] )
	{
		m_XMLTable[result] = NNXML::CreateStream( buf->GetBuffer() );
	}
	
	return m_XMLTable[result];
}
