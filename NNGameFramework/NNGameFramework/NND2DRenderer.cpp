
#include "NND2DRenderer.h"
#include "NNApplication.h"

NND2DRenderer::NND2DRenderer()
	: m_ipD2DFactory(nullptr), m_ipRenderTarget(nullptr)
{
}
NND2DRenderer::~NND2DRenderer()
{
	Release();
}

bool NND2DRenderer::Init()
{
	HRESULT hr;
	hr = D2D1CreateFactory( D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_ipD2DFactory );
	if ( hr != S_OK )
	{
		return false;
	}

	HWND hwnd = NNApplication::GetInstance()->GetHWND();
	RECT rt;
	GetClientRect( hwnd, &rt );
	D2D1_SIZE_U size = D2D1::SizeU( rt.right-rt.left, rt.bottom-rt.top );

	hr = m_ipD2DFactory->CreateHwndRenderTarget( D2D1::RenderTargetProperties(),
												 D2D1::HwndRenderTargetProperties( hwnd, size ),
												 &m_ipRenderTarget );

	if ( hr != S_OK )
	{
		return false;
	}

	return true;
}
bool NND2DRenderer::Release()
{
	SafeRelease( m_ipD2DFactory );
	SafeRelease( m_ipRenderTarget );

	return true;
}

bool NND2DRenderer::Clear()
{
	m_ipRenderTarget->Clear( D2D1::ColorF( D2D1::ColorF::White ) );
	return true;
}
bool NND2DRenderer::Begin()
{
	m_ipRenderTarget->BeginDraw();
	return true;
}
bool NND2DRenderer::End()
{
	m_ipRenderTarget->EndDraw();
	return true;
}

