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
