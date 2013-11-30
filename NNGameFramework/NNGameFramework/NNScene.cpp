
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
	
	m_Matrix = D2D1::Matrix3x2F::Translation( m_Camera.GetCenterX(), m_Camera.GetCenterY() ) *
	    D2D1::Matrix3x2F::Scale( m_Camera.GetZoom(), m_Camera.GetZoom(), D2D1::Point2F(m_Camera.GetPositionX()+m_Camera.GetCenterX(), m_Camera.GetPositionY()+m_Camera.GetCenterY()) ) *
		D2D1::Matrix3x2F::Rotation( m_Camera.GetRotation(), D2D1::Point2F(m_Camera.GetPositionX()+m_Camera.GetCenterX(),m_Camera.GetPositionY()+m_Camera.GetCenterY()) ) *
	    D2D1::Matrix3x2F::Translation( -m_Camera.GetPositionX(), -m_Camera.GetPositionY());

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

NNScene* NNScene::Create() { 
	NNScene* pInstance = new NNScene();
	return pInstance;
}