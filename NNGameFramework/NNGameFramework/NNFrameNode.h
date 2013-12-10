
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