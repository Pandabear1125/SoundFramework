#include "Sound.h"

namespace Sound {

	void Init()
	{
		Manager = SoundManager();
	}

	void Play(SoundBuffer* buffer, float x, float y)
	{
		Manager.Play(buffer, x, y);
	}

	void StopAll()
	{
		Manager.StopAll();
	}

	void Update(float dt)
	{
		Manager.Update(dt);
	}

}
