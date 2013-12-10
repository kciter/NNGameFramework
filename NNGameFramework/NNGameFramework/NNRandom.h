
/**
 * NNRandom.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 26
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#pragma once

class NNRandom
{
public:
	static int NextInt( int min, int max );
	static float NextFloat( float min, float max );
	static double NextDouble( double min, double max );
	static float NextFloat();
	static double NextDouble();

	static void ReleaseInstance()
	{
		if ( mpInstance != nullptr )
		{
			delete mpInstance;
			mpInstance = nullptr;
		}
	}

private:
	static NNRandom* mpInstance;

	NNRandom();
	~NNRandom();
};