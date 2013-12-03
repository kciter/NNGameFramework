
/**
 * NNScene.h
 * �ۼ���: �̼���
 * �ۼ���: 2013. 10. 30
 * ���������� ������ ���: �̼���
 * ������: 2013. 12. 04
 */

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

	virtual void Init() = 0;

	virtual void Render();
	virtual void Update( float dTime );

	NNCamera& GetCamera() { return m_Camera; }
	NNUISet* GetUISet() { return m_UISet; }

	void SetUISet( NNUISet* uiSet ) { m_UISet = uiSet; }

protected:
	NNCamera m_Camera;
	NNUISet* m_UISet;
};