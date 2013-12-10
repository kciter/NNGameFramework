
#include "AnimationSample.h"

AnimationSample::AnimationSample()
{
}
AnimationSample::~AnimationSample()
{
}

void AnimationSample::Init()
{
	m_Animation = NNAnimation::Create( 3, 0.1f, L"Resources/Texture/z1.png",
		L"Resources/Texture/z2.png", 
		L"Resources/Texture/z3.png");

	// �� 6�� �ִϸ��̼�
	// �� ���� �ؽ��� ��, �ڰ� ���

	m_Animation->SetPosition( NNPoint(50.f,50.f) );

	// ��� ���� ����

	AddChild( m_Animation );
}

void AnimationSample::Render()
{
	NNScene::Render();
}
void AnimationSample::Update( float eTime )
{
	NNScene::Update( eTime );
}