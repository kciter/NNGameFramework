
#include "NNAnimation.h"

NNAnimation::NNAnimation()
	: m_FrameCount(0), m_Frame(0), m_Time(0.f), m_Loop(true), m_AnimationEnd(false)
{

}
NNAnimation::~NNAnimation()
{
	m_SpriteList.clear();
}

NNAnimation* NNAnimation::Create( int count, ... )
{
	NNAnimation* pInstance = new NNAnimation();

	va_list ap;
	va_start( ap, count );

	for (int i=0; i<count; i++ )
	{
		NNSpriteNode* spriteInstance = NNSpriteNode::Create( va_arg( ap, wchar_t* ) );
		pInstance->m_SpriteList.push_back( spriteInstance );
		pInstance->m_SpriteList[i]->SetFrameTime( 0.2f );
		pInstance->AddChild( spriteInstance );
	}

	va_end( ap );

	pInstance->m_FrameCount = count;

	return pInstance;
}
NNAnimation* NNAnimation::Create()
{
	NNAnimation* pInstance = new NNAnimation();
	return pInstance;
}

void NNAnimation::AddSpriteNode( wchar_t* path )
{
	NNSpriteNode* spriteInstance = NNSpriteNode::Create( path);
	m_FrameCount++;
	m_SpriteList.push_back( spriteInstance );
	AddChild( spriteInstance );
}

void NNAnimation::Render()
{
	if ( m_AnimationEnd == true || m_Visible == false ) return;

	NNObject::Render();

	m_SpriteList[m_Frame]->Render();
}
void NNAnimation::Update( float dTime )
{
	if ( m_AnimationEnd == true || m_Visible == false ) return;

	NNObject::Update( dTime );

	m_Time += dTime;

	if ( m_Time >= m_SpriteList[m_Frame]->GetFrameTime() )
	{
		++m_Frame;
		m_Time = 0.f;
	}

	if ( m_Frame >= m_FrameCount ) 
	{
		m_Frame = 0;
		if ( m_Loop == false )
		{
			m_AnimationEnd = true;
		}
	}
}