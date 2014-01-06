
/**
 * NNFrameNode.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 07 // NNSpriteNode -> NNFrameNode
 * ���������� ������ ���: ����ȯ
 * ������: 2013. 12. 10
 */

#pragma once

#include "NNSprite.h"

class NNFrameNode : public NNObject
{
public:
	NNFrameNode();
	virtual ~NNFrameNode();

private:
	void Init(){}

	void Render();
	void Update( float dTime );

	//NNCREATE_FUNC(NNSpriteNode);

	static NNFrameNode* Create( wchar_t* path );

public:
	NNSprite* GetSprite() const { return mSprite; }
	float GetFrameTime() const { return mFrameTime; }

	void SetFrameTime( float frameTime ) { mFrameTime = frameTime; }

private:
	NNSprite* mSprite;
	float mFrameTime;

	friend class NNAnimation;
};