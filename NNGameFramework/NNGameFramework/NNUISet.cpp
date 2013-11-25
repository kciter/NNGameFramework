
#include "NNUISet.h"

NNUISet::NNUISet()
{
}
NNUISet::~NNUISet()
{

}

void NNUISet::Render()
{
	if ( m_Visible == false ) return;

	m_Matrix = D2D1::Matrix3x2F::Translation( -m_Center.GetX(), -m_Center.GetY() )* 
		D2D1::Matrix3x2F::Rotation( m_Rotation ) *
		D2D1::Matrix3x2F::Scale( m_ScaleX, m_ScaleY ) *
		D2D1::Matrix3x2F::Translation( m_Position.GetX(), m_Position.GetY() );

	for (const auto& child : m_ChildList )
	{
		child->Render();
	}
}
void NNUISet::Update( float dTime )
{
	if ( m_Visible == false ) return;

	for (const auto& child : m_ChildList)
	{
		child->Update( dTime );
	}
}