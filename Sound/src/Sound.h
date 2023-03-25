#pragma once

#include "SoundManager.h"

namespace Sound {

	static SoundManager* Manager = nullptr;

	void Init();
	void Terminate();

	// Plays an audio buffer at position x, y
	void Play(SoundBuffer* buffer, float x = 0.f, float y = 0.f);
	
	// Create a new audio buffer from a supported audio file format (.wav/.ogg)
	// This buffer pointer is internally destructed so no need for manual cleanup
	SoundBuffer* NewBuffer(std::string path);

	// Halts all current playing sounds, clears the source buffer
	void StopAll();

	void Update(float dt);

	bool IsFinished();

}