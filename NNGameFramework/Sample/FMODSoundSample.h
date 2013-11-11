
#include "NNScene.h"
#include "NNSound.h"

class FMODSoundSample : public NNScene
{
public:
	FMODSoundSample();
	virtual ~FMODSoundSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(FMODSoundSample);

private:
	NNSound* m_Sound;
	NNSound* m_Background;
};
