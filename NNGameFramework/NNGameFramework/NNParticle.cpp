
#include "NNParticle.h"
#include "NNApplication.h"
#include "NNResourceManager.h"
#include "NNConfig.h"
#include <d2d1_1.h>

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
	m_Matrix = D2D1::Matrix3x2F::Translation( -m_ImageWidth/2.f, -m_ImageHeight/2.f ) *
		D2D1::Matrix3x2F::Rotation( m_Rotation ) *
		D2D1::Matrix3x2F::Scale( m_ScaleX, m_ScaleY ) *
		D2D1::Matrix3x2F::Translation( m_Position.GetX(), m_Position.GetY() );

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

// 	ID2D1DeviceContext* context;
// 
// 	D2D1_CREATION_PROPERTIES properties;
// 	properties.debugLevel = D2D1_DEBUG_LEVEL_NONE;
// 	properties.options = D2D1_DEVICE_CONTEXT_OPTIONS_NONE;
// 	properties.threadingMode = D2D1_THREADING_MODE_SINGLE_THREADED;
// 	D2D1CreateDeviceContext( nullptr, properties, &context );
// 
// 	ID2D1Effect* saturationEffect;
// 
// 	context->CreateEffect(CLSID_D2D1Saturation, &saturationEffect);
// 
// 	// Connect the input bitmap to the effect
// 	saturationEffect->SetInput(0, m_pD2DTexture->GetD2DBitmap());
// 
// 	// Set a property to adjust the effect¡¯s behavior
// 	saturationEffect->SetValue(D2D1_SATURATION_PROP_SATURATION, 0.6f);
// 
// 	// Render the image
// 	context->BeginDraw();
// 	context->DrawImage(saturationEffect);
// 	context->EndDraw();

	

	m_pD2DRenderer->GetHwndRenderTarget()->SetTransform( m_Matrix );
	m_pD2DRenderer->GetHwndRenderTarget()->DrawBitmap(
		m_pD2DTexture->GetD2DBitmap(), D2D1::RectF(0.f,0.f,m_ImageWidth,m_ImageHeight),
		m_Color.GetOpacity() );
}

void NND2DParticle::Update( float dTime )
{
	NNParticle::Update( dTime );
}