
#include "NNSpriteNode.h"

NNSpriteNode::NNSpriteNode()
	: m_Sprite(nullptr), m_FrameTime(0.f)
{
}
NNSpriteNode::~NNSpriteNode()
{
}

NNSpriteNode* NNSpriteNode::Create( wchar_t* path )
{
	NNSpriteNode* pInstance = new NNSpriteNode();
	NNSprite* spriteInstance = NNSprite::Create( path );
	pInstance->m_Sprite = spriteInstance;

	pInstance->AddChild( spriteInstance );

	return pInstance;
}

void NNSpriteNode::Render()
{
	NNObject::Render();

	m_Sprite->Render();
}
void NNSpriteNode::Update( float dTime )
{
	NNObject::Update( dTime );
}