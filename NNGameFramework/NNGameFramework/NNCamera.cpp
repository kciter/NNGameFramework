
/**
 * NNCamera.cpp
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNCamera.h"
#include "NNApplication.h"

NNCamera::NNCamera()
	: m_Anchor(CameraAnchor::TOP_LEFT), m_Position(0.f,0.f), m_Zoom(1.f), m_Rotation(0.f),
	  m_ScreenWidth(0), m_ScreenHeight(0)
{
	m_ScreenWidth = NNApplication::GetInstance()->GetScreenWidth();
	m_ScreenHeight = NNApplication::GetInstance()->GetScreenHeight();
}
NNCamera::~NNCamera()
{

}

