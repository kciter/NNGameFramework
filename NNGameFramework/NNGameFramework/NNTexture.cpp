
#include "NNTexture.h"
#include "NNApplication.h"



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


