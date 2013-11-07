
#ifdef _DEBUG

#include "CameraSample.h"

CameraSample::CameraSample()
{
	GetCamera().SetCameraAnchor(CameraAnchor::MIDDLE_CENTER);
	GetCamera().SetZoom( 2.f );

	m_Sprite = NNSprite::Create(L"Sprite/walk_0.png");
	AddChild(m_Sprite);
}
CameraSample::~CameraSample()
{

}

void CameraSample::Render()
{
	NNScene::Render();
}
void CameraSample::Update( float dTime )
{
	NNScene::Update(dTime);
}

#endif