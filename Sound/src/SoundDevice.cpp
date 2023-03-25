#include "SoundDevice.h"

SoundDevice::SoundDevice(const ALCchar* deviceName)
{
   // open default device
   m_Device = alcOpenDevice(deviceName);
   if (!m_Device) // verify success
      __debugbreak();

   // create new context
   m_Context = alcCreateContext(m_Device, nullptr);
   if (!m_Context)   // verify success
      __debugbreak();

   // make context current
   if (!alcMakeContextCurrent(m_Context)) // verify success
      __debugbreak();

   // get name of device opened from enumerate all extension
   const ALCchar* name = nullptr;

   if (alcIsExtensionPresent(m_Device, "ALC_ENUMERATE_ALL_EXT"))
      name = alcGetString(m_Device, ALC_ALL_DEVICES_SPECIFIER);
   else
      __debugbreak();

   if (!name || !alcGetError(m_Device))
      name = alcGetString(m_Device, ALC_DEVICE_SPECIFIER);

   std::cout << "Opened Device: " << name << std::endl;
}

SoundDevice::~SoundDevice()
{
   // clear current context
   if (!alcMakeContextCurrent(nullptr))
      __debugbreak();   // verify success
   DisplayALCError("Error Unbinding Current Context", alcGetError(m_Device));

   // destroy context
   alcDestroyContext(m_Context);
   DisplayALCError("Error Destroying Context", alcGetError(m_Device));

   // close active device
   if (!alcCloseDevice(m_Device))
      __debugbreak();   // verify success
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

