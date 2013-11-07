
#pragma once

#include "Library/TinyXML/tinyxml.h"
#include "Library/TinyXML/xpath_static.h"
#include <string>

class NNXML
{
public: 
	NNXML( std::string path );
	NNXML();
	~NNXML();

	static NNXML* Create( std::string path );
	static NNXML* Create();

	TiXmlString XPathToString( std::string xpath );

private:
	TiXmlDocument m_Document;

	bool m_LoadSuccess;
};