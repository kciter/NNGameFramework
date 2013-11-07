
#ifdef _DEBUG

#include "CameraSample.h"

CameraSample::CameraSample()
{
	GetCamera().SetCameraAnchor(CameraAnchor::MIDDLE_CENTER);
	GetCamera().SetZoom( 2.f ); // 줌 2배

	// 카메라를 화면의 중심으로 즉 0.f, 0.f가 화면의 중앙으로 오게됨

	m_Sprite = NNSprite::Create(L"Resources/Texture/walk_0.png");
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