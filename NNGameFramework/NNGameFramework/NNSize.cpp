
/**
 * NNSize.cpp
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
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