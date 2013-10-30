
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


