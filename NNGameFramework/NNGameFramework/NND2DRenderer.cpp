
/**
 * NND2DRenderer.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NND2DRenderer.h"
#include "NNApplication.h"

NND2DRenderer::NND2DRenderer()
	: mipD2DFactory(nullptr), mipRenderTarget(nullptr)
{
}
NND2DRenderer::~NND2DRenderer()
{
	Release();
}

bool NND2DRenderer::Init()
{
	HRESULT hr;
	hr = D2D1CreateFactory( D2D1_FACTORY_TYPE_SINGLE_THREADED, &mipD2DFactory );
	if ( hr != S_OK )
	{
		return false;
	}

	HWND hwnd = NNApplication::GetInstance()->GetHWND();
	RECT rt;
	GetClientRect( hwnd, &rt );
	D2D1_SIZE_U size = D2D1::SizeU( rt.right-rt.left, rt.bottom-rt.top );

	hr = mipD2DFactory->CreateHwndRenderTarget( D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties( hwnd, size, D2D1_PRESENT_OPTIONS_IMMEDIATELY ),	
		&mipRenderTarget );

	if ( hr != S_OK )
	{
		return false;
	}

	return true;
}
bool NND2DRenderer::Release()
{
	SafeRelease( mipD2DFactory );
	SafeRelease( mipRenderTarget );

	return true;
}

bool NND2DRenderer::Clear()
{
	mipRenderTarget->Clear( D2D1::ColorF( D2D1::ColorF::White ) );
	return true;
}
bool NND2DRenderer::Begin()
{
	mipRenderTarget->BeginDraw();
	return true;
}
bool NND2DRenderer::End()
{
	mipRenderTarget->EndDraw();
	return true;
}

