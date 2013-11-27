
#pragma once

#include "NNConfig.h"

/* */
/* NNTexture
/* �ؽ����� ������ ��Ƴ��� Ŭ����
/* �������� ���� NNTexture Ŭ������ ���丮 Ŭ�������Ǿ�
/* �˸��� �ؽ��� Ŭ������ �����Ѵ�.
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
	static NNTexture* CreateStream( char *buf, int size );
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
	NND2DTexture( char *buf , int size );
	NND2DTexture( std::wstring path );
	virtual ~NND2DTexture();

	//void Create();
	//static NND2DTexture* Create( std::wstring path );
	void Destroy();

public:
	inline ID2D1Bitmap* GetD2DBitmap() const { return m_D2DBitmap; }
};


