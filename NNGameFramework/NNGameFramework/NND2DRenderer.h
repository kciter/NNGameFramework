
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
	ID2D1Factory* GetD2DFactory() const { return m_ipD2DFactory; }
	ID2D1HwndRenderTarget* GetHwndRenderTarget() const { return m_ipRenderTarget; }

private:
	ID2D1Factory* m_ipD2DFactory;
	ID2D1HwndRenderTarget* m_ipRenderTarget;
};