
/**
 * NNUISet.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 25
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
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