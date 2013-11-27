
#include "NNMatrix.h"

NNMatrix::NNMatrix()
{
	Identity();
}
NNMatrix::NNMatrix( float _11, float _12, float _21, float _22, float _31, float _32 )
{
	this->_11 = _11;
	this->_12 = _12;
	this->_21 = _21;
	this->_22 = _22;
	this->_31 = _31;
	this->_32 = _32;
}
NNMatrix::~NNMatrix()
{
}

void NNMatrix::Identity()
{
	_11 = 1.f;
	_12 = 0.f;
	_21 = 0.f;
	_22 = 1.f;
	_31 = 0.f;
	_32 = 0.f;
}
NNMatrix NNMatrix::Scale( NNPoint size, NNPoint center )
{
	NNMatrix instance;
	instance._11 = size.GetX(); instance._12 = 0.0;
	instance._21 = 0.0; instance._22 = size.GetY();
	instance._31 = center.GetX() - size.GetX() * center.GetX();
	instance._32 = center.GetY() - size.GetY() * center.GetY();
	return instance;
}
NNMatrix NNMatrix::Scale( float x, float y, NNPoint center )
{
	return Scale( NNPoint(x, y), center );
}
NNMatrix NNMatrix::Translate( NNPoint size )
{
	NNMatrix instance;
	instance._11 = 1.0; instance._12 = 0.0;
	instance._21 = 0.0; instance._22 = 1.0;
	instance._31 = size.GetX(); instance._32 = size.GetY();
	return instance;
}
NNMatrix NNMatrix::Translate( float x, float y )
{
	return Translate( NNPoint(x,y) );
}
NNMatrix NNMatrix::Rotation( float angle, NNPoint center )
{
	return NNMatrix();
}

bool NNMatrix::IsIdentity()
{
	return _11 == 1.f && _12 == 0.f
			&& _21 == 0.f && _22 == 1.f
			&& _31 == 0.f && _32 == 0.f;
}