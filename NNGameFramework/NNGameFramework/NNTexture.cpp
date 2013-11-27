
#include "NNTexture.h"
#include "NNApplication.h"
#include "NND2DRenderer.h"
#include "NND3DRenderer.h"

//////////////////////////////////////////////////////////////////////////
/*					NND2DTexture										*/
//////////////////////////////////////////////////////////////////////////
NNTexture* NNTexture::Create( std::wstring path )
{
	static RendererStatus rendererStatus = NNApplication::GetInstance()->GetRendererStatus();

	NNTexture* pInstance = nullptr;
	switch( rendererStatus )
	{
	case D2D:
		pInstance = new NND2DTexture( path );
		break;
	default:
		break;
	}
	
	return pInstance;
}
NNTexture* NNTexture::CreateStream( char *buf, int size )
{
	static RendererStatus rendererStatus = NNApplication::GetInstance()->GetRendererStatus();

	NNTexture* pInstance = nullptr;
	switch( rendererStatus )
	{
	case D2D:
		pInstance = new NND2DTexture( buf, size );
		break;
	default:
		break;
	}

	return pInstance;
}

//////////////////////////////////////////////////////////////////////////
/*					NND2DTexture										*/
//////////////////////////////////////////////////////////////////////////
IWICImagingFactory* NND2DTexture::g_pWICFactory = nullptr;

NND2DTexture::NND2DTexture()
	: m_D2DBitmap(nullptr), m_FmtConverter(nullptr)
{ 
}
NND2DTexture::NND2DTexture( std::wstring path )
{
	if ( g_pWICFactory == nullptr)
	{
		HRESULT ret = CoCreateInstance( CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&g_pWICFactory) );
		if( ret == REGDB_E_CLASSNOTREG ) 
		{
			CoCreateInstance( CLSID_WICImagingFactory1, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&g_pWICFactory) );
		}
	}

	m_Path = path;

	IWICBitmapDecoder* bitmapDecoder = nullptr;
	g_pWICFactory->CreateDecoderFromFilename( path.c_str(), nullptr, GENERIC_READ, 
		WICDecodeMetadataCacheOnDemand, &bitmapDecoder );

	IWICBitmapFrameDecode* bitmapFrameDecode = nullptr;
	bitmapDecoder->GetFrame( 0, &bitmapFrameDecode );

	g_pWICFactory->CreateFormatConverter( &m_FmtConverter );

	m_FmtConverter->Initialize( bitmapFrameDecode,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		nullptr,
		0.0f,
		WICBitmapPaletteTypeCustom );

	NND2DRenderer* pD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());

	pD2DRenderer->GetHwndRenderTarget()->CreateBitmapFromWicBitmap( m_FmtConverter, nullptr, &m_D2DBitmap );

	SafeRelease( bitmapDecoder );
	SafeRelease( bitmapFrameDecode );
}
NND2DTexture::NND2DTexture( char *buf, int size )
{
	if ( g_pWICFactory == nullptr)
	{
		HRESULT ret = CoCreateInstance( CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&g_pWICFactory) );
		if( ret == REGDB_E_CLASSNOTREG ) 
		{
			CoCreateInstance( CLSID_WICImagingFactory1, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&g_pWICFactory) );
		}
	}
	IWICBitmapDecoder* bitmapDecoder = nullptr;
	IWICStream* iWICStream;
	g_pWICFactory->CreateStream( &iWICStream );
	iWICStream->InitializeFromMemory( (WICInProcPointer)buf, size );
	g_pWICFactory->CreateDecoderFromStream( iWICStream, nullptr, WICDecodeMetadataCacheOnDemand, &bitmapDecoder );

	IWICBitmapFrameDecode* bitmapFrameDecode = nullptr;
	bitmapDecoder->GetFrame( 0, &bitmapFrameDecode );

	g_pWICFactory->CreateFormatConverter( &m_FmtConverter );

	m_FmtConverter->Initialize( bitmapFrameDecode,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		nullptr,
		0.0f,
		WICBitmapPaletteTypeCustom );

	NND2DRenderer* pD2DRenderer = static_cast<NND2DRenderer*>(NNApplication::GetInstance()->GetRenderer());

	pD2DRenderer->GetHwndRenderTarget()->CreateBitmapFromWicBitmap( m_FmtConverter, nullptr, &m_D2DBitmap );

	SafeRelease( bitmapDecoder );
	SafeRelease( bitmapFrameDecode );
}
NND2DTexture::~NND2DTexture()
{
	Destroy();
	SafeRelease( g_pWICFactory );
}
void NND2DTexture::Destroy()
{
	SafeRelease( m_D2DBitmap );
	SafeRelease( m_FmtConverter );
}

//////////////////////////////////////////////////////////////////////////
/*					NND3DTexture										*/
//////////////////////////////////////////////////////////////////////////
NND3DTexture::NND3DTexture()
	: mTexture(nullptr)
{
}
NND3DTexture::NND3DTexture( std::wstring path )
{
	NND3DRenderer* pD2DRenderer = static_cast<NND3DRenderer*>(NNApplication::GetInstance()->GetRenderer());

	D3DXCreateTextureFromFileEx( pD2DRenderer->GetDevice(), path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL, &mTexture );
}
NND3DTexture::~NND3DTexture()
{
	Destroy();
}

void NND3DTexture::Destroy()
{
	SafeRelease( mTexture );
}
