
/**
 * NNSize.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNSize.h"

NNSize& NNSize::operator= ( const NNSize& size )
{
	this->SetSize( size.GetX(), size.GetY(), size.GetWidth(), size.GetHeight() );
	return *this;
}
NNSize NNSize::operator-() const
{
	return NNSize( -this->mX, -this->mY, -this->mWidth, -this->mHeight );
}