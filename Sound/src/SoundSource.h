#pragma once

#include <AL/al.h>
#include <AL/alc.h>

#include "SoundBuffer.h"

class SoundSource
{
public:
	SoundSource();
	SoundSource(SoundBuffer* buffer, float x = 0.f, float y = 0.f);
	~SoundSource();

	void Update(float dt);

	bool GetState();

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

	// gets initialized to the buffer's duration when created
	// if this is 0, the source is finished playing and can be destroyed/reused
	float m_PlayTime = 0.f;
	bool m_Active = false;

};