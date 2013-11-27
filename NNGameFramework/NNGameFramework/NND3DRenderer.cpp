
#include "NND3DRenderer.h"
#include "NNApplication.h"

NND3DRenderer::NND3DRenderer()
{

}
NND3DRenderer::~NND3DRenderer()
{

}

bool NND3DRenderer::Init()
{
	HRESULT hr = 0;

	mD3D = NULL;
	mD3DDevice = NULL;

	mD3D = Direct3DCreate9( D3D_SDK_VERSION );

	ZeroMemory( &mD3DPresentParameters, sizeof(mD3DPresentParameters) );

	D3DMULTISAMPLE_TYPE mst = D3DMULTISAMPLE_NONE;

	switch(4)
	{
	case 1: mst = D3DMULTISAMPLE_NONMASKABLE;break;
	case 2: mst = D3DMULTISAMPLE_2_SAMPLES;break;
	case 3: mst = D3DMULTISAMPLE_3_SAMPLES;break;
	case 4: mst = D3DMULTISAMPLE_4_SAMPLES;break;
	case 5: mst = D3DMULTISAMPLE_5_SAMPLES;break;
	case 6: mst = D3DMULTISAMPLE_6_SAMPLES;break;
	case 7: mst = D3DMULTISAMPLE_7_SAMPLES;break;
	case 8: mst = D3DMULTISAMPLE_8_SAMPLES;break;
	case 9: mst = D3DMULTISAMPLE_9_SAMPLES;break;
	case 10: mst = D3DMULTISAMPLE_10_SAMPLES;break;
	case 11: mst = D3DMULTISAMPLE_11_SAMPLES;break;
	case 12: mst = D3DMULTISAMPLE_12_SAMPLES;break;
	case 13: mst = D3DMULTISAMPLE_13_SAMPLES;break;
	case 14: mst = D3DMULTISAMPLE_14_SAMPLES;break;
	case 15: mst = D3DMULTISAMPLE_15_SAMPLES;break;
	case 16: mst = D3DMULTISAMPLE_16_SAMPLES;break;
	default: mst = D3DMULTISAMPLE_NONE;break;
	}

	mD3DPresentParameters.Windowed = true;
	mD3DPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	mD3DPresentParameters.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	mD3DPresentParameters.BackBufferWidth = NNApplication::GetInstance()->GetScreenWidth();
	mD3DPresentParameters.BackBufferHeight = NNApplication::GetInstance()->GetScreenHeight();
	mD3DPresentParameters.BackBufferFormat = D3DFMT_A8R8G8B8;
	mD3DPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;// D3DPRESENT_INTERVAL_IMMEDIATE;
	mD3DPresentParameters.hDeviceWindow = NNApplication::GetInstance()->GetHWND();

	hr = mD3D->CheckDeviceMultiSampleType( D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL, mD3DPresentParameters.BackBufferFormat, true, mst, NULL );

	if( SUCCEEDED(hr) )
	{
		mD3DPresentParameters.MultiSampleType = mst;
	}
	else
	{
		return false;
	}

	mD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, NNApplication::GetInstance()->GetHWND(),
		D3DCREATE_HARDWARE_VERTEXPROCESSING, &mD3DPresentParameters, &mD3DDevice ); //D3DCREATE_SOFTWARE_VERTEXPROCESSING

	D3DXCreateSprite( mD3DDevice, &mSprite );

	return true;
}
bool NND3DRenderer::Release()
{
	mD3D->Release();
	mD3DDevice->Release();
	return true;
}

bool NND3DRenderer::Clear()
{
	HRESULT hr = 0;
	hr = mD3DDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255,255,255,0), 1.0f, 0 );
	if( FAILED(hr) )
		return false;

	return true;
}
bool NND3DRenderer::Begin()
{
	HRESULT hr = 0;

	hr = mD3DDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255,255,255,0), 1.0f, 0 );
	if( FAILED(hr) )
		return false;

	hr = mD3DDevice->BeginScene();
	if( FAILED(hr) )
		return false;

	return true;
}
bool NND3DRenderer::End()
{
	HRESULT hr = 0;

	hr = mD3DDevice->EndScene();
	if( FAILED(hr) )
		return false;

	hr = mD3DDevice->Present( NULL, NULL, NULL, NULL );
	if( FAILED(hr) )
		return false;

	return true;
}