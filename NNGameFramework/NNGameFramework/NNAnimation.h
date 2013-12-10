
/**
 * NNAnimationNode.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNFrameNode.h"
#include <vector>

class NNAnimation : public NNObject
{
public:
	NNAnimation();
	virtual ~NNAnimation();

	void Init(){}

	void Render();
	void Update( float dTime );

	static NNAnimation* Create( int count, ... );
	static NNAnimation* Create();

	int GetFrameCount() const { return mFrameCount; }
	int GetNowFrame() const { return mFrame; }
	bool IsLoop() const { return mLoop; }

	void AddSpriteNode( wchar_t* path );
	void SetLoop( bool loop ) { mLoop = loop; }

private:
	std::vector<NNFrameNode*> mSpriteList;

	int mFrameCount;
	int mFrame;
	float mTime;
	bool mLoop;
	bool mAnimationEnd;
};