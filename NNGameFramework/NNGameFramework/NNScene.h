
/**
 * NNScene.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

#include "NNObject.h"
#include "NNCamera.h"
#include "NNUISet.h"

/* */
/* NNScene
/* SceneDirector에 등록될 수 있는 Scene 노드
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