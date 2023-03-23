#pragma once

#include <iostream>

#include <AL/al.h>
#include <AL/alc.h>

void DisplayALError(const char* msg, ALenum error);
void DisplayALCError(const char* msg, ALCenum error);

//! OpenAL Sound Device
// Holds current OpenAL context and devices
// Should be destroyed LAST
class SoundDevice
{
public:
	SoundDevice(const ALCchar* deviceName = nullptr);
	~SoundDevice();

private:
	ALCdevice* m_Device = nullptr;
	ALCcontext* m_Context = nullptr;

};