
/**
 * NNRandom.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 26
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
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