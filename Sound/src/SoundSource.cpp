#include "SoundSource.h"

SoundSource::SoundSource()
{
	std::cout << "New Source: " << 0 << std::endl;
	alGenSources(1, &m_Source);

	alSourcef(m_Source, AL_PITCH, m_Pitch);
	alSourcef(m_Source, AL_GAIN, m_Gain);
	alSource3f(m_Source, AL_POSITION, m_Position[0], m_Position[1], m_Position[2]);
	alSource3f(m_Source, AL_VELOCITY, m_Velocity[0], m_Velocity[1], m_Velocity[2]);
	alSourcei(m_Source, AL_LOOPING, m_Loop);
	alSourcei(m_Source, AL_BUFFER, 0);

	DisplayALError("Error Creating Sound Source", alGetError());
}

SoundSource::SoundSource(SoundBuffer* buffer, float x, float y)
{
	std::cout << "New Source: " << buffer << std::endl;
	m_Position[0] = x;
	m_Position[1] = y;

	m_Buffer = buffer;

	alGenSources(1, &m_Source);

	alSourcef(m_Source, AL_PITCH, m_Pitch);
	alSourcef(m_Source, AL_GAIN, m_Gain);
	alSource3f(m_Source, AL_POSITION, m_Position[0], m_Position[1], m_Position[2]);
	alSource3f(m_Source, AL_VELOCITY, m_Velocity[0], m_Velocity[1], m_Velocity[2]);
	alSourcei(m_Source, AL_LOOPING, m_Loop);
	alSourcei(m_Source, AL_BUFFER, buffer->GetID());

	DisplayALError("Error Creating Sound Source", alGetError());

	m_PlayTime = buffer->GetDuration();
	m_Active = true;
}

SoundSource::~SoundSource()
{
	std::cout << "Deleting Source: " << m_Buffer << std::endl;
	// stop playing source
	alSourceStop(m_Source);

	// unassign buffer ID from source
	alSourcei(m_Source, AL_BUFFER, 0);

	// delete source
	alDeleteSources(1, &m_Source);

	// check for errores
	DisplayALError("Error Destroying Sound Source", alGetError());
}

void SoundSource::Update(float dt)
{
	m_PlayTime -= dt;

	if (m_PlayTime <= 0)
		m_Active = false;
}

bool SoundSource::GetState()
{
	return m_Active;
}

void SoundSource::Play(SoundBuffer* buffer)
{
	if (buffer)
	{
		if (buffer != m_Buffer)
		{
			m_Buffer = buffer;

			m_PlayTime = buffer->GetDuration();
			m_Active = true;

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
	m_Active = false;
}

void DisplayALError(const char* msg, ALenum error)
{
	const char* errorMSG = nullptr;

	switch (error)
	{
	case AL_NO_ERROR:
		return;
		break;
	case AL_INVALID_NAME:
		errorMSG = "AL_INVALID_NAME";
		break;
	case AL_INVALID_ENUM:
		errorMSG = "AL_INVALID_ENUM";
		break;
	case AL_INVALID_VALUE:
		errorMSG = "AL_INVALID_VALUE";
		break;
	case AL_INVALID_OPERATION:
		errorMSG = "AL_INVALID_OPERATION";
		break;
	case AL_OUT_OF_MEMORY:
		errorMSG = "AL_OUT_OF_MEMORY";
		break;
	default:
		errorMSG = "";
		break;
	}

	std::cout << "[AL] " << msg << ' ' << errorMSG << " (" << error << ")\n";
}

void DisplayALCError(const char* msg, ALCenum error)
{
	const char* errorMSG = nullptr;

	switch (error)
	{
	case ALC_NO_ERROR:
		return;
		break;
	case ALC_INVALID_DEVICE:
		errorMSG = "ALC_INVALID_DEVICE";
		break;
	case ALC_INVALID_ENUM:
		errorMSG = "AL_INVALID_ENUM";
		break;
	case ALC_INVALID_CONTEXT:
		errorMSG = "ALC_INVALID_CONTEXT";
		break;
	case ALC_INVALID_VALUE:
		errorMSG = "ALC_INVALID_VALUE";
		break;
	case ALC_OUT_OF_MEMORY:
		errorMSG = "ALC_OUT_OF_MEMORY";
		break;
	default:
		errorMSG = "";
		break;
	}

	std::cout << "[ALC] " << msg << ' ' << errorMSG << " (" << error << ")\n";
}

