
/**
 * NNAnimation.cpp
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 김지환
 * 수정일: 2013. 12. 10
 */

#include "NNAnimation.h"

NNAnimation::NNAnimation()
	: mFrameCount(0), mFrame(0), mTime(0.f), mLoop(true), mAnimationEnd(false)
{

}
NNAnimation::~NNAnimation()
{
	for (auto& iter=mSpriteList.begin(); iter!=mSpriteList.end(); iter++ )
	{
		SafeDelete(*iter);
	}
	mSpriteList.clear();
}

NNAnimation* NNAnimation::Create( int count, ... )
{
	NNAnimation* pInstance = new NNAnimation();

	va_list ap;
	va_start( ap, count );

	for (int i=0; i<count; i++ )
	{
		NNFrameNode* spriteInstance = NNFrameNode::Create( va_arg( ap, wchar_t* ) );
		pInstance->mSpriteList.push_back( spriteInstance );
		pInstance->mSpriteList[i]->SetFrameTime( 0.2f );
		spriteInstance->SetParent( pInstance );
		//pInstance->AddChild( spriteInstance );
	}

	va_end( ap );

	pInstance->mFrameCount = count;

	return pInstance;
}
NNAnimation* NNAnimation::Create()
{
	NNAnimation* pInstance = new NNAnimation();
	return pInstance;
}

void NNAnimation::AddSpriteNode( wchar_t* path )
{
	NNFrameNode* spriteInstance = NNFrameNode::Create( path);
	mFrameCount++;
	mSpriteList.push_back( spriteInstance );
	spriteInstance->SetParent( this );
	//AddChild( spriteInstance );
}

void NNAnimation::Render()
{
	if ( mAnimationEnd == true || mVisible == false ) return;

	NNObject::Render();

	mSpriteList[mFrame]->Render();
}
void NNAnimation::Update( float dTime )
{
	if ( mAnimationEnd == true || mVisible == false ) return;

	NNObject::Update( dTime );

	mTime += dTime;

	if ( mTime >= mSpriteList[mFrame]->GetFrameTime() )
	{
		++mFrame;
		mTime = 0.f;
	}

	if ( mFrame >= mFrameCount ) 
	{
		mFrame = 0;
		if ( mLoop == false )
		{
			mAnimationEnd = true;
		}
	}
}