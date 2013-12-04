
/**
 * NNUISet.cpp
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 25
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 05
 */

#include "NNUISet.h"

NNUISet::NNUISet()
{
}
NNUISet::~NNUISet()
{

}

void NNUISet::Render()
{
	if ( m_Visible == false ) return;\

	m_Matrix = NNMatrix::Translate( -m_Center.GetX(), -m_Center.GetY() )* 
		NNMatrix::Rotation( m_Rotation ) *
		NNMatrix::Scale( m_ScaleX, m_ScaleY ) *
		NNMatrix::Translate( m_Position.GetX(), m_Position.GetY() );

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