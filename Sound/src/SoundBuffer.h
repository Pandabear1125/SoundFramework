#pragma once

#include <vector>
#include <iostream>

#include <AL/al.h>
#include <AL/alc.h>

#include <sndfile/sndfile.h>
#include <inttypes.h>
#include <AL/alext.h>

void DisplayALError(const char* msg, ALenum error);
void DisplayALCError(const char* msg, ALCenum error);

class SoundBuffer
{
public:
	SoundBuffer(const char* audioFilename);
	~SoundBuffer();

	ALuint GetID();
	float GetDuration();

private:
	ALuint m_ID = 0;
	float m_Duration = 0.f;

};