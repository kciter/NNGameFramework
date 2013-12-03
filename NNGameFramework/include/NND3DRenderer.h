
/**
 * NND3DRenderer.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 27
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNRenderer.h"

class NND3DRenderer : public NNRenderer
{
public:
	NND3DRenderer();
	virtual ~NND3DRenderer();

public:
	bool Init();
	bool Release();

	bool Clear();
	bool Begin();
	bool End();

public:
	LPDIRECT3D9 GetD3D() { return mD3D; }
	LPDIRECT3DDEVICE9 GetDevice() { return mD3DDevice; }
	LPD3DXSPRITE GetSprite() { return mSprite; }

private:
	LPDIRECT3D9 mD3D;
	LPDIRECT3DDEVICE9 mD3DDevice;
	LPD3DXSPRITE mSprite;
	D3DPRESENT_PARAMETERS mD3DPresentParameters;
};