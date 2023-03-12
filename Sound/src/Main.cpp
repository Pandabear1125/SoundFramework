#include <iostream>

#include <AL/al.h>
#include <AL/alc.h>

#include "SoundDevice.h"
#include "SoundSource.h"
#include "SoundBuffer.h"

void DisplayALError(const char* msg, ALenum error);
void DisplayALCError(const char* msg, ALCenum error);

int main()
{
	std::cout << "Starting Application!" << std::endl;

	SoundDevice device;

	SoundSource source;

	SoundBuffer buffer("res/gmae.wav");

	source.Play(&buffer);
	
	std::cin.get();
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

