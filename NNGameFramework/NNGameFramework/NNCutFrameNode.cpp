
#include "NNCutFrameNode.h"

NNCutFrameNode::NNCutFrameNode()
	: mFrameTime(0.2f)
{
	
}
NNCutFrameNode::~NNCutFrameNode()
{

}

void NNCutFrameNode::Init()
{
}
void NNCutFrameNode::Render()
{
	NNObject::Render();
}
void NNCutFrameNode::Update( float dTime )
{
	NNObject::Update( dTime );
}

NNCutFrameNode* NNCutFrameNode::Create( std::wstring path, NNSize size )
{
	NNCutFrameNode* pInstance = new NNCutFrameNode();

	NNSpriteAtlas* spriteInstance = NNSpriteAtlas::Create( path );
	pInstance->mSpriteAtlas = spriteInstance;
	pInstance->mSpriteAtlas->SetCutSize( size );
	pInstance->AddChild( spriteInstance );

	return pInstance;
}