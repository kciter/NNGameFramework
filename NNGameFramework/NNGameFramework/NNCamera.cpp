
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
	: mAnchor(CameraAnchor::TOP_LEFT), mPosition(0.f,0.f), mZoom(1.f), mRotation(0.f),
	  mScreenWidth(0), mScreenHeight(0)
{
	mScreenWidth = NNApplication::GetInstance()->GetScreenWidth();
	mScreenHeight = NNApplication::GetInstance()->GetScreenHeight();
}
NNCamera::~NNCamera()
{

}

