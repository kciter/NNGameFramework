
/**
 * NNPoint
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
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