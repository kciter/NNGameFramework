
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

private:
	LPDIRECT3D9 mD3D;
	LPDIRECT3DDEVICE9 mD3DDevice;
	D3DPRESENT_PARAMETERS mD3DPresentParameters;
};