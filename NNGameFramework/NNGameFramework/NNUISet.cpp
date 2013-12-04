
/**
 * NNUISet.cpp
 * 작성자: 이선협
 * 작성일: 2013. 11. 25
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 05
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