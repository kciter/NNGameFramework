
/**
 * NNMatrix.cpp
 * 작성자: 이선협
 * 작성일: 2013. 11. 27
 * 마지막으로 수정한 사람: 김지환
 * 수정 이유 : Rotate 연산을 Degree로 계산함. 그리고 오류 수정
 * 수정일: 2013. 12. 10
 */

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
	_11 = 1.f; _12 = 0.f;
	_21 = 0.f; _22 = 1.f;
	_31 = 0.f; _32 = 0.f;
}
NNMatrix NNMatrix::Scale( NNPoint size )
{
	NNMatrix instance;
	instance._11 = size.GetX(); instance._12 = 0.0f;
	instance._21 = 0.0f; instance._22 = size.GetY();
	instance._31 = 0.0f; instance._32 = 0.0f;
	return instance;
}
NNMatrix NNMatrix::Scale( float x, float y )
{
	return Scale( NNPoint(x, y) );
}
NNMatrix NNMatrix::Translate( NNPoint size )
{
	NNMatrix instance;
	instance._11 = 1.0f; instance._12 = 0.0f;
	instance._21 = 0.0f; instance._22 = 1.0f;
	instance._31 = size.GetX(); instance._32 = size.GetY();
	return instance;
}
NNMatrix NNMatrix::Translate( float x, float y )
{
	return Translate( NNPoint(x,y) );
}
NNMatrix NNMatrix::Rotation( float angle )
{
	NNMatrix instance;
	instance._11 = cos(angle); instance._12 = sin(angle);
	instance._21 = -sin(angle); instance._22 = cos(angle);
	instance._31 = 0.0f; instance._32 = 0.0f;
	return instance;
}

bool NNMatrix::IsIdentity() const
{
	return _11 == 1.f && _12 == 0.f
			&& _21 == 0.f && _22 == 1.f
			&& _31 == 0.f && _32 == 0.f;
}

float NNMatrix::Determinant() const
{
	return (_11 * _22) - (_12 * _21);
}

NNMatrix& NNMatrix::operator= ( const NNMatrix& matrix )
{
	this->_11 = matrix._11; this->_12 = matrix._12;
	this->_21 = matrix._21; this->_22 = matrix._22;
	this->_31 = matrix._31; this->_32 = matrix._32;
	return *this;
}
NNMatrix NNMatrix::operator+( const NNMatrix& matrix ) const
{
	return NNMatrix( 
		this->_11+matrix._11, this->_12+matrix._12,
		this->_21+matrix._21, this->_22+matrix._22,
		this->_31+matrix._31, this->_32+matrix._32 );
}
NNMatrix NNMatrix::operator-( const NNMatrix& matrix ) const
{
	return NNMatrix(
		this->_11-matrix._11, this->_12-matrix._12,
		this->_21-matrix._21, this->_22-matrix._22,
		this->_31-matrix._31, this->_32-matrix._32 );
}
NNMatrix NNMatrix::operator-() const
{
	return NNMatrix(
		-this->_11, -this->_12,
		-this->_21, -this->_22,
		-this->_31, -this->_32 );
}
NNMatrix NNMatrix::operator*( float n ) const
{
	return NNMatrix(
		-this->_11*n, -this->_12*n,
		-this->_21*n, -this->_22*n,
		-this->_31*n, -this->_32*n );
}
NNMatrix NNMatrix::operator/( float n ) const
{
	return NNMatrix(
		-this->_11/n, -this->_12/n,
		-this->_21/n, -this->_22/n,
		-this->_31/n, -this->_32/n );
}
NNMatrix NNMatrix::operator*( const NNMatrix& matrix ) const
{
	return NNMatrix(
		this->_11*matrix._11 + this->_12*matrix._21,
		this->_11*matrix._12 + this->_12*matrix._22,
		this->_21*matrix._11 + this->_22*matrix._21,
		this->_21*matrix._12 + this->_22*matrix._22,
		this->_31*matrix._11 + this->_32*matrix._21 + matrix._31,
		this->_31*matrix._12 + this->_32*matrix._22 + matrix._32 );
}