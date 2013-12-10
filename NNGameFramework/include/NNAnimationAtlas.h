
#pragma once

#include "NNObject.h"
#include "NNCutFrameNode.h"
#include <string>
#include <vector>

class NNAnimationAtlas : public NNObject
{
public:
	NNAnimationAtlas();
	virtual ~NNAnimationAtlas();

	void Init(){}

	void Render();
	void Update( float dTime );

	static NNAnimationAtlas* Create( std::wstring path, int count, float frameTime, ... );
	static NNAnimationAtlas* Create( std::wstring path );

	int GetFrameCount() const { return mFrameCount; }
	int GetNowFrame() const { return mFrame; }
	bool IsLoop() const { return mLoop; }

	void AddFrameNode( wchar_t* path );
	void SetLoop( bool loop ) { mLoop = loop; }

	void SetFrameTimeInSection(float frameRate, int start, int end);
	float GetPlayTime();
	std::vector<NNCutFrameNode*> GetFrameList() { return mFrameList; }
	NNCutFrameNode* GetFrame( int index ) { return mFrameList[index]; }

private:
	std::wstring mPath;
	std::vector<NNCutFrameNode*> mFrameList;

	int mFrameCount;
	int mFrame;
	float mTime;
	bool mLoop;
	bool mAnimationEnd;
};