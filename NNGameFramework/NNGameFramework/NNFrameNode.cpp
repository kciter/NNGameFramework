
/**
 * NNFrameNode.h
 * 작성자: 이선협
 * 작성일: 2013. 11. 07 // NNSpriteNode -> NNFrameNode
 * 마지막으로 수정한 사람: 김지환
 * 수정일: 2013. 12. 10
 */

#include "NNFrameNode.h"

NNFrameNode::NNFrameNode()
	: mSprite(nullptr), mFrameTime(0.f)
{
}
NNFrameNode::~NNFrameNode()
{
}

NNFrameNode* NNFrameNode::Create( wchar_t* path )
{
	NNFrameNode* pInstance = new NNFrameNode();
	NNSprite* spriteInstance = NNSprite::Create( path );
	pInstance->mSprite = spriteInstance;

	pInstance->AddChild( spriteInstance );

	return pInstance;
}

void NNFrameNode::Render()
{
	NNObject::Render();

	//mSprite->Render();
}
void NNFrameNode::Update( float dTime )
{
	NNObject::Update( dTime );
}