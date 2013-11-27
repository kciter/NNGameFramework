
#pragma once

#include "NNConfig.h"

/* */
/* NNRenderer
/* 출력을 담당하는 렌더러 인터페이스
/* */

enum RendererStatus
{
	UNKNOWN,
	D2D,
	D3D,
};

class NNRenderer
{
public:
	NNRenderer(){}
	virtual ~NNRenderer(){}

public:
	virtual bool Init() = 0;
	virtual bool Release() = 0;

	virtual bool Begin() = 0;
	virtual bool End() = 0;
	virtual bool Clear() = 0;
};


