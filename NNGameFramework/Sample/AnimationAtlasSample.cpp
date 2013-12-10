
#include "AnimationAtlasSample.h"

AnimationAtlasSample::AnimationAtlasSample()
	: mAnimationAtlas(nullptr)
{

}
AnimationAtlasSample::~AnimationAtlasSample()
{

}

void AnimationAtlasSample::Init()
{
	mAnimationAtlas = NNAnimationAtlas::Create( L"Resources/Texture/map.png", 3, 0.2f, NNSize(0,0,10,10), NNSize(10,10,20,20), NNSize(0,0,30,30) );
	AddChild( mAnimationAtlas );
}
void AnimationAtlasSample::Render()
{
	NNObject::Render();
}
void AnimationAtlasSample::Update( float dTime )
{
	NNObject::Update( dTime );
}