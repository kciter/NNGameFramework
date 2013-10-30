
#pragma once

#include "NNConfig.h"

/* */
/* NNTexture
/* 텍스쳐의 정보를 담아놓은 클래스
/* 렌더러에 따라 NNTexture 클래스가 팩토리 클래스가되어
/* 알맞은 텍스쳐 클래스를 생성한다.
/* */

class NNTexture
{
protected:
	std::wstring m_Path;

public:
	NNTexture(){}
	virtual ~NNTexture(){}

	//virtual NNTexture* Create() = 0;
	static NNTexture* Create( std::wstring path );
	virtual void Destroy() = 0;
};

class NND2DTexture : public NNTexture
{
private:
	static IWICImagingFactory* g_pWICFactory;
	ID2D1Bitmap* m_D2DBitmap;
	IWICFormatConverter* m_FmtConverter;

public:
	NND2DTexture();
	NND2DTexture( std::wstring path );
	virtual ~NND2DTexture();

	//void Create();
	//static NND2DTexture* Create( std::wstring path );
	void Destroy();

public:
	inline ID2D1Bitmap* GetD2DBitmap() const { return m_D2DBitmap; }
};


