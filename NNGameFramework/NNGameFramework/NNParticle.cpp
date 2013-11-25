
#include "NNParticle.h"
#include "NNApplication.h"
#include "NNResourceManager.h"

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
	m_pD2DRenderer->GetHwndRenderTarget()->SetTransform( m_Matrix );
	m_pD2DRenderer->GetHwndRenderTarget()->DrawBitmap( 
		m_pD2DTexture->GetD2DBitmap(), D2D1::RectF(0.f,0.f,m_ImageWidth,m_ImageHeight),
		m_Color.GetOpacity() );
}

void NND2DParticle::Update( float dTime )
{
	m_LifeTime += dTime;
}