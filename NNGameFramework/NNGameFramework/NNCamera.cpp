
/**
 * NNCamera.cpp
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 08
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
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

