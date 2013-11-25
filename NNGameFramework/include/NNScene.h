
#pragma once

#include "NNObject.h"
#include "NNCamera.h"
#include "NNUISet.h"

/* */
/* NNScene
/* SceneDirector�� ��ϵ� �� �ִ� Scene ���
/* */

class NNScene : public NNObject
{
public:
	NNScene();
	virtual ~NNScene();

	static NNScene* Create();

	virtual void Render();
	virtual void Update( float dTime );

	NNCamera& GetCamera() { return m_Camera; }
	NNUISet* GetUISet() { return m_UISet; }

	void SetUISet( NNUISet* uiSet ) { m_UISet = uiSet; }

protected:
	NNCamera m_Camera;
	NNUISet* m_UISet;
};