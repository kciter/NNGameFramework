
/**
 * NNPoint
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#include "NNPoint.h"

NNPoint& NNPoint::operator= ( const NNPoint& point )
{
	this->SetPoint( point.GetX(), point.GetY() );
	return *this;
}
NNPoint NNPoint::operator+( const NNPoint& point ) const
{
	return NNPoint( this->mX+point.GetX(), this->mY+point.GetY() );
}
NNPoint NNPoint::operator-( const NNPoint& point ) const
{
	return NNPoint( this->mX-point.GetX(), this->mY-point.GetY() );
}
NNPoint NNPoint::operator-() const
{
	return NNPoint( -this->mX, -this->mY );
}
NNPoint NNPoint::operator*( float n ) const
{
	return NNPoint( this->mX*n, this->mY*n );
}
NNPoint NNPoint::operator/( float n ) const
{
	return NNPoint( this->mX/n, this->mY/n );
}