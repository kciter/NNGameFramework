
/**
 * NNAnimationNode.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 08
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
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