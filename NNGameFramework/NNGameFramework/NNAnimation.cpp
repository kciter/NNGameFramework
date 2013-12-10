
/**
 * NNAnimation.cpp
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정 이유: 네이밍 변경 Sprite -> Frame
 *			  SetFrameRate 네이밍 변경 SetFrameRate -> SetFrameTimeInSection
 * 수정일: 2013. 12. 10
 */

#include "NNAnimation.h"

NNAnimation::NNAnimation()
	: mFrameCount(0), mFrame(0), mTime(0.f), mLoop(true), mAnimationEnd(false)
{

}
NNAnimation::~NNAnimation()
{
	for (auto& iter=mFrameList.begin(); iter!=mFrameList.end(); iter++ )
	{
		SafeDelete(*iter);
	}
	mFrameList.clear();
}

NNAnimation* NNAnimation::Create( int count, float frameTime, ... )
{
	NNAnimation* pInstance = new NNAnimation();

	va_list ap;
	va_start( ap, frameTime );

	for (int i=0; i<count; i++ )
	{
		NNFrameNode* spriteInstance = NNFrameNode::Create( va_arg( ap, wchar_t* ) );
		pInstance->mFrameList.push_back( spriteInstance );
		pInstance->mFrameList[i]->SetFrameTime( frameTime );
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

void NNAnimation::AddFrameNode( wchar_t* path )
{
	NNFrameNode* spriteInstance = NNFrameNode::Create( path);
	mFrameCount++;
	mFrameList.push_back( spriteInstance );
	spriteInstance->SetParent( this );
	//AddChild( spriteInstance );
}

void NNAnimation::Render()
{
	if ( mAnimationEnd == true || mVisible == false ) return;

	NNObject::Render();

	mFrameList[mFrame]->Render();
}
void NNAnimation::Update( float dTime )
{
	if ( mAnimationEnd == true || mVisible == false ) return;

	NNObject::Update( dTime );

	mTime += dTime;

	if ( mTime >= mFrameList[mFrame]->GetFrameTime() )
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

void NNAnimation::SetFrameTimeInSection( float frameRate, int start, int end )
{
	for (; start <= end; ++start)
		mFrameList[start]->SetFrameTime(frameRate);
}

float NNAnimation::GetPlayTime()
{
	float result = 0.f;

	for ( int i=0; i< mFrameCount; ++i)
		result += mFrameList[i]->GetFrameTime();

	return result;
}
