#pragma once

#include <vector>
#include <iostream>
#include <inttypes.h>

// OpenAL
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

// sndfile
#include <sndfile/sndfile.h>

static void DisplayALError(const char* msg, ALenum error);
static void DisplayALCError(const char* msg, ALCenum error);

//! OpenAL Sound Buffer
// Holds OpenAL IDs to stored audio data and a max duration value
// Should be destroyed after sources
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