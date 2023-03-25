#include "SoundManager.h"

SoundManager::SoundManager()
{
	m_Device = new SoundDevice();
}

SoundManager::~SoundManager()
{
	// clean up all sources
	for (auto& source : m_Sources)
	{
		delete source;
	}

	// clean up all buffers
	for (auto& buffer : m_Buffers)
	{
		delete buffer;
	}

	// clean up device
	delete m_Device;
}

void SoundManager::Update(float dt)
{
	// for every source
	for (auto itr = m_Sources.begin(); itr != m_Sources.end();)
	{
		// update playtime
		(*itr)->Update(dt);

		// delete if source is finished playing it's buffer
		if (!(*itr)->GetState())
		{
			delete (*itr);
			itr = m_Sources.erase(itr);
		}
		else 
			itr++;
	}

	// update state
	if (m_Sources.empty())
		m_Done = true;
	else
		m_Done = false;
}

SoundBuffer* SoundManager::AddBuffer(std::string path)
{
	SoundBuffer* buffer = new SoundBuffer(path.c_str());

	m_Buffers.push_back(buffer);

	return buffer;
}

void SoundManager::Play(SoundBuffer* buffer, float x, float y)
{
	SoundSource* source = new SoundSource(buffer, x, y);

	m_Sources.push_back(source);

	source->Play();
}

void SoundManager::StopAll()
{
	// for all sources
	for (auto itr = m_Sources.begin(); itr != m_Sources.end();)
	{
		// clean up and erase
		delete (*itr);
		itr = m_Sources.erase(itr);
	}
}

bool SoundManager::IsFinished()
{
	return m_Done;
}
