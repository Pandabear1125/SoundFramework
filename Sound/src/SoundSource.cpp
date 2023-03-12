#include "SoundSource.h"

SoundSource::SoundSource()
{
	alGenSources(1, &m_Source);

	alSourcef(m_Source, AL_PITCH, m_Pitch);
	alSourcef(m_Source, AL_GAIN, m_Gain);
	alSource3f(m_Source, AL_POSITION, m_Position[0], m_Position[1], m_Position[2]);
	alSource3f(m_Source, AL_VELOCITY, m_Velocity[0], m_Velocity[1], m_Velocity[2]);
	alSourcei(m_Source, AL_LOOPING, m_Loop);
	alSourcei(m_Source, AL_BUFFER, 0);

	DisplayALError("Error Creating Sound Source", alGetError());
}

SoundSource::~SoundSource()
{
	// unassign buffer ID from source
	alSourcei(m_Source, AL_BUFFER, 0);

	// delete source
	alDeleteSources(1, &m_Source);

	// check for errores
	DisplayALError("Error Destroying Sound Source", alGetError());
}

void SoundSource::Play(SoundBuffer* buffer)
{
	if (buffer)
	{
		if (buffer != m_Buffer)
		{
			m_Buffer = buffer;
			alSourcei(m_Source, AL_BUFFER, (ALint)m_Buffer->GetID());
		}

		alSourcePlay(m_Source);
	}
	else
	{
		if (m_Buffer)
			alSourcePlay(m_Source);
	}
}

void SoundSource::Pause()
{
	alSourcePause(m_Source);
}
