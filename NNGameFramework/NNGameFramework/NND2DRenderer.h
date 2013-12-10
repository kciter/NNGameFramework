
/**
 * NND2DRenderer.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

#pragma once

#include "NNRenderer.h"

/* */
/* NND2DRenderer
/* Direct2D ������� ����ϴ� ������
/* */

class NND2DRenderer : public NNRenderer
{
public:
	NND2DRenderer();
	virtual ~NND2DRenderer();

public:
	bool Init();
	bool Release();

	bool Clear();
	bool Begin();
	bool End();

public:
	ID2D1Factory* GetD2DFactory() const { return mipD2DFactory; }
	ID2D1HwndRenderTarget* GetHwndRenderTarget() const { return mipRenderTarget; }

private:
	ID2D1Factory* mipD2DFactory;
	ID2D1HwndRenderTarget* mipRenderTarget;
};