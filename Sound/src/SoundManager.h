#pragma once

#include "SoundSource.h"
#include "SoundDevice.h"

//! Custom Sound Manager
// Handles all OpenAL context, source, and buffer state
// Manages audio playback and source/buffer creation/deletion
// Fully handles destruction of OpenAL state
class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void Update(float dt);

public:
	SoundBuffer* AddBuffer(std::string path);

	void Play(SoundBuffer* buffer, float x = 0.f, float y = 0.f);

	void StopAll();

	bool IsFinished();

private:
	std::vector<SoundSource*> m_Sources;
	std::vector<SoundBuffer*> m_Buffers;
	SoundDevice* m_Device = nullptr;

	bool m_Done = false;

};