
#include "LabelSample.h"

LabelSample::LabelSample()
{
	m_Label = NNLabel::Create( L"asdf", L"���� ���", 20.f );
	AddChild( m_Label );
}
LabelSample::~LabelSample()
{
}

void LabelSample::Render()
{
	NNScene::Render();
}
void LabelSample::Update( float dTime )
{
	NNScene::Update( dTime );
}