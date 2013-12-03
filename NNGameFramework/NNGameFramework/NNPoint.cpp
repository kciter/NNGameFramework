
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