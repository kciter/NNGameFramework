
#include "NNSound.h"
#include "NNApplication.h"



NNSound::NNSound()
	: m_Playing(false)
{
}
NNSound::~NNSound()
{
	Destroy();
}

void NNSound::Create( std::wstring path )
{
	MCI_OPEN_PARMS mciOpen = {0};
	MCIERROR mciError = {0};

	mciOpen.lpstrDeviceType = L"waveaudio";//(LPCWSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;
	mciOpen.lpstrElementName = path.c_str();

	mciError = mciSendCommand( NULL, MCI_OPEN, MCI_OPEN_ELEMENT|MCI_OPEN_TYPE, (DWORD)&mciOpen );
	if ( mciError )
	{
		return;
	}

	m_MciDevice = mciOpen.wDeviceID;
	m_Playing = false;
}

void NNSound::Destroy()
{
	if ( m_Playing )
	{
		Stop();
	}
	if ( m_MciDevice )
	{
		mciSendCommand( m_MciDevice, MCI_CLOSE, 0, 0 );
	}
}

void NNSound::Play()
{
	if ( !m_MciDevice )
	{
		return;
	}
	MCI_PLAY_PARMS mciPlay = {0};
	MCIERROR mciError = {0};

	mciPlay.dwCallback = (DWORD_PTR)NNApplication::GetInstance()->GetHWND();
	mciError = mciSendCommand( m_MciDevice, MCI_PLAY, MCI_FROM|MCI_NOTIFY, (DWORD)&mciPlay );
	if ( !mciError )
	{
		m_Playing = true;
	}
}
void NNSound::Pause()
{
	if ( !m_MciDevice )
	{
		return;
	}
	mciSendCommand( m_MciDevice, MCI_PAUSE, 0, 0 );
}
void NNSound::Resume()
{
	if ( !m_MciDevice )
	{
		return;
	}
	mciSendCommand( m_MciDevice, MCI_RESUME, 0, 0 );
}
void NNSound::Stop()
{
	if ( !m_MciDevice )
	{
		return;
	}
	mciSendCommand( m_MciDevice, MCI_STOP, 0, 0 );
	m_Playing = false;
}

