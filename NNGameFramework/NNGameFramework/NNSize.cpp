
#include "NNSize.h"



NNSize& NNSize::operator= ( const NNSize& size )
{
	this->SetSize( size.GetWidth(), size.GetHeight() );
	return *this;
}
NNSize NNSize::operator+( const NNSize& size ) const
{
	return NNSize( this->m_Width+size.GetWidth(), this->m_Height+size.GetHeight() );
}
NNSize NNSize::operator-( const NNSize& size ) const
{
	return NNSize( this->m_Width-size.GetWidth(), this->m_Height-size.GetHeight() );
}
NNSize NNSize::operator-() const
{
	return NNSize( -this->m_Width, -this->m_Height );
}
NNSize NNSize::operator*( float n ) const
{
	return NNSize( this->m_Width*n, this->m_Height*n );
}
NNSize NNSize::operator/( float n ) const
{
	return NNSize( this->m_Width/n, this->m_Height/n );
}


