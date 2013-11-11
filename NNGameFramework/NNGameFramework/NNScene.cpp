
#include "NNScene.h"

NNScene::NNScene()
{
}
NNScene::~NNScene()
{

}

void NNScene::Render()
{
	if ( m_Visible == false ) return;
	
	m_Matrix = D2D1::Matrix3x2F::Translation( m_Camera.GetCenterX(), m_Camera.GetCenterY() ) *
		D2D1::Matrix3x2F::Rotation( m_Camera.GetRotation(), D2D1::Point2F(m_Camera.GetPositionX()+m_Camera.GetCenterX(),m_Camera.GetPositionY()+m_Camera.GetCenterY()) ) *
	    D2D1::Matrix3x2F::Scale( m_Camera.GetZoom(), m_Camera.GetZoom(), D2D1::Point2F(m_Camera.GetPositionX()+m_Camera.GetCenterX(), m_Camera.GetPositionY()+m_Camera.GetCenterY()) ) *
	    D2D1::Matrix3x2F::Translation( -m_Camera.GetPositionX(), -m_Camera.GetPositionY());

	for (const auto& child : m_ChildList )
	{
		child->Render();
	}
}
void NNScene::Update( float dTime )
{
	if ( m_Visible == false ) return;

	for (const auto& child : m_ChildList)
	{
		child->Update( dTime );
	}
}

NNScene* NNScene::Create() { 
	NNScene* pInstance = new NNScene();
	return pInstance;
}