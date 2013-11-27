
#pragma once

#include "NNRenderer.h"
#include "Library/DirectX/Include/d3d9.h"
#include "Library/DirectX/Include/d3dx9.h"

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

private:
	LPDIRECT3D9 mD3D;
	LPDIRECT3DDEVICE9 mD3DDevice;
	D3DPRESENT_PARAMETERS mD3DPresentParameters;
};