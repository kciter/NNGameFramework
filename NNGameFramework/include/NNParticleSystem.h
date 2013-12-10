
/**
 * NNParticleSystem.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNObject.h"
#include "NNParticle.h"
#include <list>

class NNParticleSystem : public NNObject
{
public:
	NNParticleSystem();
	virtual ~NNParticleSystem();

	void Init(){}

	void Render();
	void Update( float dTime );

	static NNParticleSystem* Create( std::wstring path );

public:
	bool IsCreate() const { return mIsCreate; }
	int GetCount() const { return mParticleList.size(); }
	int GetCreateParticlePerSecond() const { return mCreateParticlePerSecond; }

	float GetMinLifeTime() const { return mMinLifeTime; }
	float GetMaxLifeTime() const { return mMaxLifeTime; }

	float GetMinStartSpeed() const { return mMinStartSpeed; }
	float GetMaxStartSpeed() const { return mMaxStartSpeed; }

	float GetMinEndSpeed() const { return mMinEndSpeed; }
	float GetMaxEndSpeed() const { return mMaxEndSpeed; }

	float GetMinStartRotationSpeed() const { return mMinStartRotationSpeed; }
	float GetMaxStartRotationSpeed() const { return mMaxStartRotationSpeed; }

	float GetMinEndRotationSpeed() const { return mMinEndRotationSpeed; }
	float GetMaxEndRotationSpeed() const { return mMaxEndRotationSpeed; }

	float GetMinStartScaleX() const { return mMinStartScaleX; }
	float GetMaxStartScaleX() const { return mMaxStartScaleX; }

	float GetMinStartScaleY() const { return mMinStartScaleY; }
	float GetMaxStartScaleY() const { return mMaxStartScaleY; }

	float GetMinEndScaleX() const { return mMinEndScaleX; }
	float GetMaxEndScaleX() const { return mMaxEndScaleX; }

	float GetMinEndScaleY() const { return mMinEndScaleY; }
	float GetMaxEndScaleY() const { return mMaxEndScaleY; }

	float GetDirection() const { return mDirection; }

	float GetSpreadDegree() const { return mSpreadDegree; }

	float GetMinStartRodiusX() const { return mMinStartRadiusX; }
	float GetMaxStartRodiusX() const { return mMaxStartRadiusX; }

	float GetMinStartRodiusY() const { return mMinStartRadiusY; }
	float GetMaxStartRodiusY() const { return mMaxStartRadiusY; }

	NNColor GetMinStartColor() { return mMinStartColor; }
	NNColor GetMaxStartColor() { return mMaxStartColor; }

	NNColor GetMinEndColor() { return mMinEndColor; }
	NNColor GetMaxEndColor() { return mMaxEndColor; }

	void SetCreate( bool isCreate ) { mIsCreate = isCreate; }

	void SetCreateParticlePerSecond( int createParticlePerSecond ) {  mCreateParticlePerSecond = createParticlePerSecond; }

	void SetMinLifeTime( float minLifeTime ) { mMinLifeTime = minLifeTime; }
	void SetMaxLifeTime( float maxLifeTime ) { mMaxLifeTime = maxLifeTime; }

	void SetMinStartSpeed( float minStartSpeed ) { mMinStartSpeed = minStartSpeed; }
	void SetMaxStartSpeed( float maxStartSpeed ) { mMaxStartSpeed = maxStartSpeed; }

	void SetMinEndSpeed( float  minEndSpeed ) { mMinEndSpeed = minEndSpeed; }
	void SetMaxEndSpeed( float maxEndSpeed ) { mMaxEndSpeed = maxEndSpeed; }

	void SetMinStartRotationSpeed( float minStartRotationSpeed ) { mMinStartRotationSpeed = minStartRotationSpeed; }
	void SetMaxStartRotationSpeed( float maxStartRotationSpeed ) { mMaxStartRotationSpeed = maxStartRotationSpeed; }

	void SetMinEndRotationSpeed( float minEndRotationSpeed ) { mMinEndRotationSpeed = minEndRotationSpeed; }
	void SetMaxEndRotationSpeed( float maxEndRotationSpeed ) { mMaxEndRotationSpeed = maxEndRotationSpeed; }

	void SetMinStartScaleX( float minStartScaleX ) { mMinStartScaleX = minStartScaleX; }
	void SetMaxStartScaleX( float maxStartScaleX) { mMaxStartScaleX = maxStartScaleX; }

	void SetMinStartScaleY( float minStartScaleY ) { mMinStartScaleY = minStartScaleY; }
	void SetMaxStartScaleY( float maxStartScaleY) { mMaxStartScaleY = maxStartScaleY; }

	void SetMinEndScaleX( float minEndScaleX ) { mMinEndScaleX = minEndScaleX; }
	void SetMaxEndScaleX( float maxEndScaleX ) { mMaxEndScaleX = maxEndScaleX; }

	void SetMinEndScaleY( float minEndScaleY ) { mMinEndScaleY = minEndScaleY; }
	void SetMaxEndScaleY( float maxEndScaleY) { mMaxEndScaleY = maxEndScaleY; }

	void SetDirection( float direction ) { mDirection = direction; }

	void SetSpreadDegree( float spreadDegree ) { mSpreadDegree = spreadDegree; }

	void SetMinStartRodiusX( float minStartRadiusX ) { mMinStartRadiusX = minStartRadiusX; }
	void SetMaxStartRodiusX( float mxStartRadiusX ) { mMaxStartRadiusX = mxStartRadiusX ; }

	void SetMinStartRodiusY( float minStartRadiusY ) { mMinStartRadiusY = minStartRadiusY; }
	void SetMaxStartRodiusY( float maxStartRadiusY ) { mMaxStartRadiusY = maxStartRadiusY; }

	void SetMinStartColor( NNColor startColor ) { mMinStartColor = startColor; }
	void SetMaxStartColor( NNColor startColor ) { mMaxStartColor = startColor; }

	void SetMinEndColor( NNColor endColor) { mMinEndColor = endColor; }
	void SetMaxEndColor( NNColor endColor) { mMaxEndColor = endColor; }

private:
	void CreateParticle();

private:
	NNParticle** mParticlePool;
	std::list<NNParticle*> mParticleList;

	std::wstring mTexturePath; //
	
	int mPoolCount;

	bool mIsCreate;

	int mCreateParticlePerSecond;
	float mTimer;
	
	float mMinLifeTime, mMaxLifeTime;

	float mMinStartSpeed, mMaxStartSpeed;
	float mMinEndSpeed, mMaxEndSpeed;

	float mMinStartRotationSpeed, mMaxStartRotationSpeed;
	float mMinEndRotationSpeed, mMaxEndRotationSpeed;

	float mMinStartScaleX, mMaxStartScaleX;
	float mMinStartScaleY, mMaxStartScaleY;
	float mMinEndScaleX, mMaxEndScaleX;
	float mMinEndScaleY, mMaxEndScaleY;

	float mDirection;
	float mSpreadDegree;

	float mMinStartRadiusX, mMaxStartRadiusX;
	float mMinStartRadiusY, mMaxStartRadiusY;

	NNColor mMinStartColor, mMaxStartColor;
	NNColor mMinEndColor, mMaxEndColor;
};