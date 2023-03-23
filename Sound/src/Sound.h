#pragma once

#include "SoundManager.h"

namespace Sound {

	static SoundManager Manager;

	void Init();

	void Play(SoundBuffer* buffer, float x, float y);

	void StopAll();

	void Update(float dt);

}