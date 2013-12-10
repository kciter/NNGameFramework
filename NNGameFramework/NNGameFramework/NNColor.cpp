
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
	return NNColor( this->mRed+color.GetRed(), this->mGreen+color.GetGreen(), this->mBlue+color.GetBlue(), this->GetAlpha()+color.GetAlpha() );
}
NNColor NNColor::operator-( const NNColor& color ) const
{
	return NNColor( this->mRed-color.GetRed(), this->mGreen-color.GetGreen(), this->mBlue-color.GetBlue(), this->GetAlpha()-color.GetAlpha() );
}
NNColor NNColor::operator-() const
{
	return NNColor( -this->mRed, -this->mGreen, -this->mBlue, -this->GetAlpha() );
}
NNColor NNColor::operator*( float n ) const
{
	return NNColor( static_cast<int>(this->mRed*n), static_cast<int>(this->mGreen*n), static_cast<int>(this->mBlue*n), static_cast<int>(this->GetAlpha()*n) );
}
NNColor NNColor::operator/( float n ) const
{
	return NNColor( static_cast<int>(this->mRed/n), static_cast<int>(this->mGreen/n), static_cast<int>(this->mBlue/n), static_cast<int>(this->GetAlpha()/n) );
}