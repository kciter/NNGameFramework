
#include "NNRandom.h"
#include <time.h>
#include <stdlib.h>

NNRandom* NNRandom::m_pInstance = nullptr;

int NNRandom::NextInt( int min, int max )
{
	if ( max == 0 ) 
		return 0;
	else if ( max == min )
		return min;

	return (rand()%(max-min))+min;
}
float NNRandom::NextFloat( float min, float max )
{
	if ( max == 0 )
		return 0;
	else if ( max == min )
		return min;

	float point = float(rand())/float(rand());
	if ( point > 1 )
		point -= (int)point;

	if ( int(max-min) == 0 )
		return min+point;

	return (rand()%int(max-min))+min + point;
}
double NNRandom::NextDouble( double min, double max )
{
	if ( max == 0 )
		return 0;
	else if ( max == min )
		return min;

	double point = double(rand())/double(rand());
	if ( point > 1 )
		point -= (int)point;

	return (rand()%int(max-min))+min + point;
}
float NNRandom::NextFloat()
{
	float point = float(rand())/float(rand());
	if ( point > 1 )
		point -= (int)point;

	return point;
}
double NNRandom::NextDouble()
{
	double point = double(rand())/double(rand());
	if ( point > 1 )
		point -= (int)point;

	return point;
}

NNRandom::NNRandom()
{
	srand((unsigned int)time(NULL));
}
NNRandom::~NNRandom()
{

}