
/**
 * NNScene.cpp
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 05
 */

#include "NNScene.h"

NNScene::NNScene()
	: m_UISet(nullptr)
{
}
NNScene::~NNScene()
{
	SafeDelete(m_UISet);
}

void NNScene::Render()
{
	if ( m_Visible == false ) return;

	m_Matrix = NNMatrix::Translate( m_Camera.GetCenterX(), m_Camera.GetCenterY() ) *
		NNMatrix::Scale( m_Camera.GetZoom(), m_Camera.GetZoom() ) *
		NNMatrix::Rotation( m_Camera.GetRotation() ) *
		NNMatrix::Translate( -m_Camera.GetPositionX(), -m_Camera.GetPositionY());

	for (const auto& child : m_ChildList )
	{
		if ( child->IsVisible() == true )
		{
			child->Render();
		}
	}

	if ( m_UISet != nullptr )
	{
		if ( m_UISet->IsVisible() == true )
		{
			m_UISet->Render();
		}
	}
}
void NNScene::Update( float dTime )
{
	if ( m_Visible == false ) return;

	for (const auto& child : m_ChildList)
	{
		if ( child->IsVisible() == true )
		{
			child->Update( dTime );
		}
	}

	if ( m_UISet != nullptr )
	{
		if ( m_UISet->IsVisible() == true )
		{
			m_UISet->Update( dTime );
		}
	}
}