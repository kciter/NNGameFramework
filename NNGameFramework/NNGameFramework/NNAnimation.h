
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

	int GetFrameCount() const { return m_FrameCount; }
	int GetNowFrame() const { return m_Frame; }
	bool IsLoop() const { return m_Loop; }

	void AddSpriteNode( wchar_t* path );
	void SetLoop( bool loop ) { m_Loop = loop; }

private:
	std::vector<NNFrameNode*> m_SpriteList;

	int m_FrameCount;
	int m_Frame;
	float m_Time;
	bool m_Loop;
	bool m_AnimationEnd;
};