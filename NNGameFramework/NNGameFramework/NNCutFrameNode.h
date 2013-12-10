
#pragma once

#include "NNObject.h"
#include "NNSpriteAtlas.h"

class NNCutFrameNode : public NNObject
{
public:
	NNCutFrameNode();
	virtual ~NNCutFrameNode();

	void Init();
	void Render();
	void Update( float dTime );

	static NNCutFrameNode* Create( wchar_t* path, NNSize size );

	NNSpriteAtlas* GetSpriteAtlas() const { return mSpriteAtlas; }
	float GetFrameTime() const { return mFrameTime; }

	void SetFrameTime( float frameTime ) { mFrameTime = frameTime; }

private:
	NNSpriteAtlas* mSpriteAtlas;
	float mFrameTime;

	friend class NNAnimationAtlas;
};