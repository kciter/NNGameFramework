
#include "NNPoint.h"



NNPoint& NNPoint::operator= ( const NNPoint& point )
{
	this->SetPoint( point.GetX(), point.GetY() );
	return *this;
}
NNPoint NNPoint::operator+( const NNPoint& point ) const
{
	return NNPoint( this->m_X+point.GetX(), this->m_Y+point.GetY() );
}
NNPoint NNPoint::operator-( const NNPoint& point ) const
{
	return NNPoint( this->m_X-point.GetX(), this->m_Y-point.GetY() );
}
NNPoint NNPoint::operator-() const
{
	return NNPoint( -this->m_X, -this->m_Y );
}
NNPoint NNPoint::operator*( float n ) const
{
	return NNPoint( this->m_X*n, this->m_Y*n );
}
NNPoint NNPoint::operator/( float n ) const
{
	return NNPoint( this->m_X/n, this->m_Y/n );
}