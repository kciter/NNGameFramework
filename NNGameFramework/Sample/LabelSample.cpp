
#include "LabelSample.h"

LabelSample::LabelSample()
{
}
LabelSample::~LabelSample()
{
}

void LabelSample::Init()
{
	m_Label = NNLabel::Create( L"asdf", L"���� ���", 20.f );
	AddChild( m_Label );
}

void LabelSample::Render()
{
	NNScene::Render();
}
void LabelSample::Update( float dTime )
{
	NNScene::Update( dTime );
}