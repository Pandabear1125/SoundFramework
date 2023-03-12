#pragma once

#include <AL/al.h>
#include <AL/alc.h>

#include "SoundBuffer.h"

class SoundSource
{
public:
	SoundSource();
	~SoundSource();

	void Play(SoundBuffer* buffer = nullptr);
	void Pause();

private:
	// AL IDs
	ALuint m_Source = 0;
	SoundBuffer* m_Buffer = nullptr; 

	float m_Pitch = 1.f;
	float m_Gain = 1.f;
	float m_Position[3] = {};
	float m_Velocity[3] = {};
	bool	m_Loop = false;

};