
/**
 * NNAnimationNode.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 08
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 10
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

	static NNAnimation* Create( int count, float frameTime, ... );
	static NNAnimation* Create();

	int GetFrameCount() const { return mFrameCount; }
	int GetNowFrame() const { return mFrame; }
	bool IsLoop() const { return mLoop; }

	void AddFrameNode( wchar_t* path );
	void SetLoop( bool loop ) { mLoop = loop; }

	void SetFrameTimeInSection(float frameRate, int start, int end);
	float GetPlayTime();
	std::vector<NNFrameNode*> GetFrameList() { return mFrameList; }
	NNFrameNode* GetFrame( int index ) { return mFrameList[index]; }

private:
	std::vector<NNFrameNode*> mFrameList;

	int mFrameCount;
	int mFrame;
	float mTime;
	bool mLoop;
	bool mAnimationEnd;
};