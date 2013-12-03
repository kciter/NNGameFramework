
/**
 * NNFrameNode.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 07 // NNSpriteNode -> NNFrameNode
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#include "NNFrameNode.h"

NNFrameNode::NNFrameNode()
	: m_Sprite(nullptr), m_FrameTime(0.f)
{
}
NNFrameNode::~NNFrameNode()
{
}

NNFrameNode* NNFrameNode::Create( wchar_t* path )
{
	NNFrameNode* pInstance = new NNFrameNode();
	NNSprite* spriteInstance = NNSprite::Create( path );
	pInstance->m_Sprite = spriteInstance;

	pInstance->AddChild( spriteInstance );

	return pInstance;
}

void NNFrameNode::Render()
{
	NNObject::Render();

	//m_Sprite->Render();
}
void NNFrameNode::Update( float dTime )
{
	NNObject::Update( dTime );
}