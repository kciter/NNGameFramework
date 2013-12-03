
/**
 * NNColor.cpp
 * 작성자: 이선협
 * 작성일: 2013. 11. 20
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNColor.h"

NNColor& NNColor::operator= ( const NNColor& color )
{
	this->SetRGBA( color.GetRed(), color.GetGreen(), color.GetBlue(), color.GetAlpha() );
	return *this;
}
NNColor NNColor::operator+( const NNColor& color ) const
{
	return NNColor( this->m_Red+color.GetRed(), this->m_Green+color.GetGreen(), this->m_Blue+color.GetBlue(), this->GetAlpha()+color.GetAlpha() );
}
NNColor NNColor::operator-( const NNColor& color ) const
{
	return NNColor( this->m_Red-color.GetRed(), this->m_Green-color.GetGreen(), this->m_Blue-color.GetBlue(), this->GetAlpha()-color.GetAlpha() );
}
NNColor NNColor::operator-() const
{
	return NNColor( -this->m_Red, -this->m_Green, -this->m_Blue, -this->GetAlpha() );
}
NNColor NNColor::operator*( float n ) const
{
	return NNColor( static_cast<int>(this->m_Red*n), static_cast<int>(this->m_Green*n), static_cast<int>(this->m_Blue*n), static_cast<int>(this->GetAlpha()*n) );
}
NNColor NNColor::operator/( float n ) const
{
	return NNColor( static_cast<int>(this->m_Red/n), static_cast<int>(this->m_Green/n), static_cast<int>(this->m_Blue/n), static_cast<int>(this->GetAlpha()/n) );
}