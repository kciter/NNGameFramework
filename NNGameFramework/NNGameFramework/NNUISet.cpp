
/**
 * NNUISet.cpp
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 25
 * ���������� ������ ���: �̼���
 * ��������: IsVisible�� ������� ��µǴ� ���� ����
 * ������: 2013. 12. 11
 */

#include "NNUISet.h"

NNUISet::NNUISet()
{
}
NNUISet::~NNUISet()
{

}

void NNUISet::Render()
{
	if ( mVisible == false ) return;

	mMatrix = NNMatrix::Translate( -mCenter.GetX(), -mCenter.GetY() )* 
		NNMatrix::Rotation( mRotation ) *
		NNMatrix::Scale( mScaleX, mScaleY ) *
		NNMatrix::Translate( mPosition.GetX(), mPosition.GetY() );

	for (const auto& child : mChildList )
	{
		if ( child->IsVisible() == true )
		{
			child->Render();
		}
	}
}
void NNUISet::Update( float dTime )
{
	if ( mVisible == false ) return;

	for (const auto& child : mChildList)
	{
		if ( child->IsVisible() == true )
		{
			child->Update( dTime );
		}
	}
}