
#pragma once

#include <string>

enum ConsoleColor {
	_BLACK, _DARK_BLUE, _DARK_GREEN, _DARK_SKY_BLUE, _DARK_RED, _DARK_VOILET, _DARK_YELLOW, 
	_GRAY, _DARK_GRAY, _BLUE, _GREEN, _SKY_BLUE, _RED, _VOILET, _YELLOW, _WHITE,
};

class NNLogger
{
public:
	static void InfoLog( std::string string );
	static void WarningLog( std::string string );
	static void ErrorLog( std::string string );
	static void FatalLog( std::string string );
	static void TraceLog( std::string string );
	static void DebugLog( std::string string );

private:
	NNLogger();
	~NNLogger();
};