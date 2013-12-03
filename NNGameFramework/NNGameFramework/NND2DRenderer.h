
/**
 * NND2DRenderer.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNRenderer.h"

/* */
/* NND2DRenderer
/* Direct2D 기반으로 출력하는 렌더러
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