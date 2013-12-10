
#include "CutFrameNode.h"

NNCutFrameNode::NNCutFrameNode()
	: mFrameTime(0.2f)
{
	
}
NNCutFrameNode::~NNCutFrameNode()
{

}

void NNCutFrameNode::Init()
{\
}
void NNCutFrameNode::Render()
{
	NNObject::Render();
}
void NNCutFrameNode::Update( float dTime )
{
	NNObject::Update( dTime );
}

NNCutFrameNode* NNCutFrameNode::Create( wchar_t* path, NNSize size )
{
	NNCutFrameNode* pInstance = new NNCutFrameNode();

	pInstance->mSpriteAtlas = NNSpriteAtlas::Create( path );
	pInstance->mSpriteAtlas->SetCutSize( size );

	return pInstance;
}