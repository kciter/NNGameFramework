
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
	GetCamera().SetZoom( 3.f ); // ¡‹ 2πË
	//GetCamera().SetRotation(90.f);

	// ƒ´∏ﬁ∂Û∏¶ »≠∏È¿« ¡ﬂΩ…¿∏∑Œ ¡Ô 0.f, 0.f∞° »≠∏È¿« ¡ﬂæ”¿∏∑Œ ø¿∞‘µ 

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
	NNLogger::WarningLog("«Ê§ª§ª");
	NNLogger::InfoLog("«Ê§ª§ª");
	NNLogger::ErrorLog("«Ê§ª§ª");
	NNLogger::TraceLog("«Ê§ª§ª");
	NNLogger::DebugLog("«Ê§ª§ª");
	NNLogger::FatalLog("«Ê§ª§ª");
}
