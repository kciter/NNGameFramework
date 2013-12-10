
/**
 * NNXML.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 08
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#pragma once

#include "Library/TinyXML/tinyxml.h"
#include "Library/TinyXML/xpath_static.h"
#include <string>

class NNXML
{
public: 
	NNXML( std::string path );
	NNXML( char *buf );
	NNXML();
	~NNXML();

public:
	TiXmlString XPathToString( std::string xpath );
	TiXmlDocument* GetDoc(){ return &mDocument; }

private:
	static NNXML* Create( std::string path );
	static NNXML* Create();
	static NNXML* CreateStream( char* buf );

private:
	TiXmlDocument mDocument;
	bool mLoadSuccess;

	friend class NNResourceManager;
};