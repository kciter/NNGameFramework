
/**
 * NNUISet.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 25
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNObject.h"

class NNUISet : public NNObject
{
public:
	NNUISet();
	virtual ~NNUISet();

	virtual void Init() = 0;

	void Render();
	void Update( float dTime );
};