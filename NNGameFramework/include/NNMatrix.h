
/**
 * NNMatrix.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 27
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNConfig.h"
#include "NNPoint.h"

class NNMatrix
{
public:
	NNMatrix( float _11, float _12, float _21, float _22, float _31, float _32 );
	NNMatrix();
	~NNMatrix();

	void Identity();
	bool IsIdentity();

	static NNMatrix Scale( NNPoint size, NNPoint center );
	static NNMatrix Scale( float x, float y, NNPoint center );
	static NNMatrix Translate( NNPoint size );
	static NNMatrix Translate( float x, float y );
	static NNMatrix Rotation( float angle, NNPoint center );

private:
	float _11;
	float _12;
	float _21;
	float _22;
	float _31;
	float _32;
};