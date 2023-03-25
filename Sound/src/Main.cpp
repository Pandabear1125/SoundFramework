#include <iostream>

#include <AL/al.h>
#include <AL/alc.h>

#include <chrono>
#include <thread>

#include "Sound.h"

// main used for testing only, this will eventually be a static library
int main()
{
	std::cout << "Starting Application!" << std::endl;

	Sound::Init();

	auto* buffer = Sound::NewBuffer("res/gmae.wav");

	for (size_t i = 0; i < 20; i++)
	{
		Sound::Play(buffer);
	}

	int i = 0;

	while (!Sound::IsFinished())
	{
		i++;
		Sound::Update(1 / 60.f);
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}

	std::cout << "Finished" << std::endl;

	Sound::Terminate();
}

