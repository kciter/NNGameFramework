
#pragma once

#include "NNObject.h"

/* */
/* NNScene
/* SceneDirector에 등록될 수 있는 Scene 노드
/* */

class NNScene : virtual public NNObject
{
public:
	NNScene(){}
	virtual ~NNScene(){}

public:
	static NNScene* Create() { 
		NNScene* pInstance = new NNScene();
		return pInstance;
	}

	void Render(){}
	void Update( float dTime ){}
};