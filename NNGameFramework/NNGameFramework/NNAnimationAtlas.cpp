/**
* NNAnimationAtlas.cpp
* 작성자: 이선협
* 작성일: 2013. 
* 마지막으로 수정한 사람: 김지환
* 수정일: 2013. 12. 16
* 수정 이유 : 정의만 되어있던 GetPlayTime()과 SetFrameTimeInSection() 구현.
*/

#include "NNAnimationAtlas.h"

NNAnimationAtlas::NNAnimationAtlas()
	: mFrameCount(0), mFrame(0), mTime(0.f), mLoop(true), mAnimationEnd(false)
{

}
NNAnimationAtlas::~NNAnimationAtlas()
{
	for (auto& iter=mFrameList.begin(); iter!=mFrameList.end(); iter++ )
	{
		SafeDelete(*iter);
	}
	mFrameList.clear();
}

void NNAnimationAtlas::Render()
{
	if ( mAnimationEnd == true || mVisible == false ) return;
	NNObject::Render();
	mFrameList[mFrame]->Render();
}
void NNAnimationAtlas::Update( float dTime )
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

NNAnimationAtlas* NNAnimationAtlas::Create( std::wstring path, int count, float frameTime, ... )
{
	NNAnimationAtlas* pInstance = new NNAnimationAtlas();
	pInstance->mPath = path;

	va_list ap;
	va_start( ap, frameTime );

	for (int i=0; i<count; i++ )
	{
		NNCutFrameNode* spriteInstance = NNCutFrameNode::Create( path.c_str(), va_arg( ap, NNSize ) );
		pInstance->mFrameList.push_back( spriteInstance );
		pInstance->mFrameList[i]->SetFrameTime( frameTime );
		spriteInstance->SetParent( pInstance );
	}

	va_end( ap );

	pInstance->mFrameCount = count;

	return pInstance;
}
NNAnimationAtlas* NNAnimationAtlas::Create( std::wstring path )
{
	NNAnimationAtlas* pInstance = new NNAnimationAtlas();
	pInstance->mPath = path;

	return pInstance;
}
void NNAnimationAtlas::SetFrameTimeInSection(float frameRate, int start, int end)
{
	for (; start <= end; ++start)
		mFrameList[start]->SetFrameTime(frameRate);
}

float NNAnimationAtlas::GetPlayTime()
{
	float result = 0.f;

	for (int i = 0; i < mFrameCount; ++i)
		result += mFrameList[i]->GetFrameTime();

	return result;
}