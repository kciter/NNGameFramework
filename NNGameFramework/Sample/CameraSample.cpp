
#include "CameraSample.h"
#include "NNLogger.h"

CameraSample::CameraSample()
{
}
CameraSample::~CameraSample()
{
}

void CameraSample::Init()
{
	GetCamera().SetCameraAnchor(CameraAnchor::MIDDLE_CENTER);
	//GetCamera().SetPosition(100.f,100.f);
	GetCamera().SetZoom( 3.f ); // 捜 2壕
	//GetCamera().SetRotation(90.f);

	// 朝五虞研 鉢檎税 掻宿生稽 聡 0.f, 0.f亜 鉢檎税 掻肖生稽 神惟喫

	m_Sprite = NNSprite::Create(L"Resources/Texture/walk_0.png");
	AddChild(m_Sprite);
}

void CameraSample::Render()
{
	NNScene::Render();
}
void CameraSample::Update( float dTime )
{
	NNScene::Update(dTime);
	NNLogger::WarningLog("陪せせ");
	NNLogger::InfoLog("陪せせ");
	NNLogger::ErrorLog("陪せせ");
	NNLogger::TraceLog("陪せせ");
	NNLogger::DebugLog("陪せせ");
	NNLogger::FatalLog("陪せせ");
}
