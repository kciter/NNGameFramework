
/**
 * NNRenderer.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

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


