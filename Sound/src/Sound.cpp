#include "Sound.h"

namespace Sound {

	void Init()
	{
		Manager = new SoundManager();
	}

	void Terminate()
	{
		delete Manager;
	}

	void Play(SoundBuffer* buffer, float x, float y)
	{
		Manager->Play(buffer, x, y);
	}

	void StopAll()
	{
		Manager->StopAll();
	}

	bool IsFinished()
	{
		return Manager->IsFinished();
	}

	void Update(float dt)
	{
		Manager->Update(dt);
	}

	SoundBuffer* NewBuffer(std::string path)
	{
		return Manager->AddBuffer(path);
	}

}
