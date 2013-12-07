
#pragma once

#include <string>

enum ConsoleColor {
	BLACK, DARK_BLUE, DARK_GREEN, DARK_SKY_BLUE, DARK_RED, DARK_VOILET, DARK_YELLOW, 
	GRAY, DARK_GRAY, BLUE, GREEN, SKY_BLUE, RED, VOILET, YELLOW, WHITE,
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