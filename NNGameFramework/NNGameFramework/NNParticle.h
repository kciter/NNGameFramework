
#pragma once

#include "NNConfig.h"
#include "NNPoint.h"
#include "NNSize.h"
#include "NNColor.h"

class NNParticle
{
public:
	NNParticle();
	virtual ~NNParticle();

	void Render();
	void Update( float dTime );

private:
	D2D1::Matrix3x2F m_Matrix;
	NNPoint m_Position;
	float m_ScaleX;
	float m_ScaleY;
	float m_Rotation; // Degree
	bool m_Visible;
	NNColor m_Color;
};