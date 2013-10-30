
#pragma once

#include "NNRenderer.h"

/* */
/* NND2DRenderer
/* Direct2D 기반으로 출력하는 렌더러
/* */

class NND2DRenderer : public NNRenderer
{
private:
	ID2D1Factory* m_ipD2DFactory;
	ID2D1HwndRenderTarget* m_ipRenderTarget;

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
};


