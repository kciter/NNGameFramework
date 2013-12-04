
/**
 * NNParticle.cpp
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 08
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#include "NNParticle.h"
#include "NNApplication.h"
#include "NNResourceManager.h"
#include "NNConfig.h"

//////////////////////////////////////////////////////////////////////////
/*					NNParticle											*/
//////////////////////////////////////////////////////////////////////////

NNParticle* NNParticle::Create( std::wstring path )
{
	static RendererStatus rendererStatus = NNApplication::GetInstance()->GetRendererStatus();

	NNParticle* pInstance = nullptr;
	switch ( rendererStatus )
	{
	case D2D:
		pInstance = new NND2DParticle( path );
		break;
	default:
		break;
	}
	
	return pInstance;
}

void NNParticle::Render()
{
	m_Matrix = NNMatrix::Translate( -m_ImageWidth/2.f, -m_ImageHeight/2.f ) *
		NNMatrix::Rotation( m_Rotation ) *
		NNMatrix::Scale( m_ScaleX, m_ScaleY ) *
		NNMatrix::Translate( m_Position.GetX(), m_Position.GetY() );

	m_Matrix = m_Matrix * m_ParentMatrix;
}
void NNParticle::Update( float dTime )
{
	m_NowLifeTime += dTime;

	m_Speed = m_StartSpeed + (m_EndSpeed-m_StartSpeed)*(m_NowLifeTime/m_LifeTime);
	m_RotationSpeed = m_StartRotationSpeed + (m_EndRotationSpeed-m_StartRotationSpeed)*(m_NowLifeTime/m_LifeTime);

	m_Position = m_Position + NNPoint( cos(NNDegreeToRadian(m_Direction)), sin(NNDegreeToRadian(m_Direction)) ) * m_Speed * dTime;
	m_Rotation += m_RotationSpeed * dTime;

	m_ScaleX = (m_StartScaleX + (m_EndScaleX-m_StartScaleX)*(m_NowLifeTime/m_LifeTime));
	m_ScaleY = (m_StartScaleY + (m_EndScaleY-m_StartScaleY)*(m_NowLifeTime/m_LifeTime));
	m_Color = (m_StartColor + (m_EndColor-m_StartColor)*(m_NowLifeTime/m_LifeTime));
}


//////////////////////////////////////////////////////////////////////////
/*					NND2DParticle										*/
//////////////////////////////////////////////////////////////////////////
NND2DParticle::NND2DParticle()
	: m_pD2DRenderer(nullptr), m_pD2DTexture(nullptr)
{

}
NND2DParticle::NND2DParticle( std::wstring path )
{
	m_pD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());
	m_pD2DTexture = static_cast<NND2DTexture*>(NNResourceManager::GetInstance()->LoadTextureFromFile( path ));

	m_ImageWidth = m_pD2DTexture->GetD2DBitmap()->GetSize().width;
	m_ImageHeight = m_pD2DTexture->GetD2DBitmap()->GetSize().height;
}
NND2DParticle::~NND2DParticle()
{
	Destroy();
}
void NND2DParticle::Destroy()
{
	m_pD2DRenderer = nullptr;
	m_pD2DTexture = nullptr;
}

void NND2DParticle::Render()
{
	NNParticle::Render();

// 	���� ��� �߰��ؾ���

	m_D2DMatrix._11 = m_Matrix._11; m_D2DMatrix._12 = m_Matrix._12;
	m_D2DMatrix._21 = m_Matrix._21; m_D2DMatrix._22 = m_Matrix._22;
	m_D2DMatrix._31 = m_Matrix._31; m_D2DMatrix._32 = m_Matrix._32;

	m_pD2DRenderer->GetHwndRenderTarget()->SetTransform( m_D2DMatrix );
	m_pD2DRenderer->GetHwndRenderTarget()->DrawBitmap(
		m_pD2DTexture->GetD2DBitmap(), D2D1::RectF(0.f,0.f,m_ImageWidth,m_ImageHeight),
		m_Color.GetOpacity() );
}

void NND2DParticle::Update( float dTime )
{
	NNParticle::Update( dTime );
}