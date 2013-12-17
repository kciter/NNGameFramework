
#include "NNLogger.h"
#include <windows.h>
#include <iostream>

void NNLogger::InfoLog( std::string string )
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColor::_GRAY);
	std::cout << "INFO:: " << string << std::endl;
}
void NNLogger::WarningLog( std::string string )
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColor::_YELLOW);
	std::cout << "WARNING:: " << string << std::endl;
}
void NNLogger::ErrorLog( std::string string )
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColor::_RED);
	std::cout << "ERROR:: " << string << std::endl;
}
void NNLogger::FatalLog( std::string string )
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColor::_VOILET);
	std::cout << "FATAL:: " << string << std::endl;
}
void NNLogger::TraceLog( std::string string )
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColor::_SKY_BLUE);
	std::cout << "TRACE:: " << string << std::endl;
}
void NNLogger::DebugLog( std::string string )
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColor::_WHITE);
	std::cout << "DEBUG:: " << string << std::endl;
}