
/**
 * NNFrameNode.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 11. 07 // NNSpriteNode -> NNFrameNode
 * ���������� ������ ���: ����ȯ
 * ������: 2013. 12. 10
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