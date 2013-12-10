
/**
 * NNParticleSystem.cpp
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNParticleSystem.h"
#include "NNRandom.h"

NNParticleSystem::NNParticleSystem()
	: mIsCreate(true), mCreateParticlePerSecond(180),
	mMinLifeTime(1.f), mMaxLifeTime(1.f),
	mMinStartSpeed(100.f), mMaxStartSpeed(100.f),
	mMinEndSpeed(200.f), mMaxEndSpeed(200.f),
	mMinStartRotationSpeed(30.f), mMaxStartRotationSpeed(30.f),
	mMinEndRotationSpeed(90.f), mMaxEndRotationSpeed(90.f),
	mMinStartScaleX(1.f), mMaxStartScaleX(1.f),
	mMinStartScaleY(1.f), mMaxStartScaleY(1.f),
	mMinEndScaleX(2.f), mMaxEndScaleX(2.f),
	mMinEndScaleY(2.f), mMaxEndScaleY(2.f),
	mDirection(0.f), mSpreadDegree(360.f),
	mMinStartRadiusX(0.f), mMaxStartRadiusX(0.f),
	mMinStartRadiusY(0.f), mMaxStartRadiusY(0.f),
	mMinStartColor(255,255,255,1.f), mMaxStartColor(255,255,255,1.f),
	mMinEndColor(0,0,0,0.f), mMaxEndColor(0,0,0,0.f),
	mTimer(0.f), mPoolCount(0), mParticlePool(nullptr)
{
}

NNParticleSystem::~NNParticleSystem()
{
	for ( const auto& iter : mParticleList )
	{
		delete iter;
	}
	mParticleList.clear();
}

NNParticleSystem* NNParticleSystem::Create( std::wstring path )
{
	NNParticleSystem* pInstance = new NNParticleSystem();
	pInstance->mTexturePath = path;

	return pInstance;
}

void NNParticleSystem::Render()
{
	NNObject::Render();

	for ( const auto& iter : mParticleList )
	{
		iter->Render();
	}
}

void NNParticleSystem::Update( float dTime )
{
	NNObject::Update( dTime );

	if ( mIsCreate == true )
	{
		mTimer += dTime;
		if ( mTimer >= 1.f/mCreateParticlePerSecond)
		{
			for (int i=0; i< 2*dTime*mCreateParticlePerSecond/(mMinLifeTime+mMaxLifeTime); i++ )
			{
				CreateParticle();
			}
			mTimer = 0.f;
		}
	}

	for (auto& iter=mParticleList.begin(); iter!=mParticleList.end(); iter++ )
	{
		(*iter)->Update( dTime );
		if ( (*iter)->GetNowLifeTime() > (*iter)->GetLifeTime() )
		{
			delete *iter;
			iter = mParticleList.erase( iter );
			if ( iter == mParticleList.end() )
			{
				break;
			}
		}
	}
}

void NNParticleSystem::CreateParticle()
{
	NNParticle* pInstance = NNParticle::Create( mTexturePath );

	pInstance->SetParentMatrix( this->mMatrix );
	
	float tempDirection = NNDegreeToRadian(NNRandom::NextFloat(mDirection-mSpreadDegree/2.f,mDirection+mSpreadDegree/2.f));
	pInstance->SetPosition(
		NNRandom::NextFloat(mMinStartRadiusX, mMaxStartRadiusX)*cos(tempDirection),
		NNRandom::NextFloat(mMinStartRadiusX, mMaxStartRadiusX)*sin(tempDirection) );

	pInstance->SetStartSpeed( NNRandom::NextFloat(mMinStartSpeed, mMaxStartSpeed) );
	pInstance->SetEndSpeed( NNRandom::NextFloat(mMinEndSpeed, mMaxEndSpeed) );

	pInstance->SetStartScaleX( NNRandom::NextFloat(mMinStartScaleX, mMaxStartScaleX) );
	pInstance->SetStartScaleY( NNRandom::NextFloat(mMinStartScaleY, mMaxStartScaleY) );
	pInstance->SetEndScaleX( NNRandom::NextFloat(mMinEndScaleX, mMaxEndScaleX) );
	pInstance->SetEndScaleY( NNRandom::NextFloat(mMinEndScaleY, mMaxEndScaleY) );

	pInstance->SetStartRotationSpeed( NNRandom::NextFloat(mMinStartRotationSpeed, mMaxStartRotationSpeed) );
	pInstance->SetEndRotationSpeed( NNRandom::NextFloat(mMinEndRotationSpeed, mMaxEndRotationSpeed) );

	pInstance->SetDirection( NNRandom::NextFloat(mDirection-mSpreadDegree/2.f, mDirection+mSpreadDegree/2.f) );

	pInstance->SetLifeTime( NNRandom::NextFloat(mMinLifeTime, mMaxLifeTime) );

	pInstance->SetStartRGBA( 
		NNRandom::NextInt(mMinStartColor.GetRed(), mMaxStartColor.GetRed()),
		NNRandom::NextInt(mMinStartColor.GetGreen(), mMaxStartColor.GetGreen()),
		NNRandom::NextInt(mMinStartColor.GetBlue(), mMaxStartColor.GetBlue()),
		NNRandom::NextInt(mMinStartColor.GetAlpha(), mMaxStartColor.GetAlpha()) );
	pInstance->SetEndRGBA( 
		NNRandom::NextInt(mMinEndColor.GetRed(), mMaxEndColor.GetRed()),
		NNRandom::NextInt(mMinEndColor.GetGreen(), mMaxEndColor.GetGreen()),
		NNRandom::NextInt(mMinEndColor.GetBlue(), mMaxEndColor.GetBlue()),
		NNRandom::NextInt(mMinEndColor.GetAlpha(), mMaxEndColor.GetAlpha()) );

	mParticleList.push_back( pInstance );
}