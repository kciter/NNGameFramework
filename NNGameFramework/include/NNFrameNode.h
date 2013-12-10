
/**
 * NNFrameNode.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 07 // NNSpriteNode -> NNFrameNode
 * 마지막으로 수정한 사람: 김지환
 * 수정일: 2013. 12. 10
 */

#pragma once

#include "NNSprite.h"

class NNFrameNode : public NNObject
{
public:
	NNFrameNode();
	virtual ~NNFrameNode();

	void Init(){}

	void Render();
	void Update( float dTime );

	//NNCREATE_FUNC(NNSpriteNode);

	static NNFrameNode* Create( wchar_t* path );

public:
	NNSprite* GetSprite() const { return m_Sprite; }
	float GetFrameTime() const { return m_FrameTime; }

	void SetFrameTime( float frameTime ) { m_FrameTime = frameTime; }

private:
	NNSprite* m_Sprite;
	float m_FrameTime;
};