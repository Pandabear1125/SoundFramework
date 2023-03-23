#include "SoundManager.h"

SoundManager::SoundManager()
{
	m_Device = new SoundDevice();
}

SoundManager::~SoundManager()
{
	for (auto& source : m_Sources)
	{
		delete source;
	}

	for (auto& buffer : m_Buffers)
	{
		delete buffer;
	}

	delete m_Device;
}

void SoundManager::Update(float dt)
{
	for (auto itr = m_Sources.begin(); itr != m_Sources.end();)
	{
		(*itr)->Update(dt);

		if (!(*itr)->GetState())
		{
			delete (*itr);
			itr = m_Sources.erase(itr);
		}
		else 
			itr++;
	}

	if (m_Sources.empty())
		m_Done = true;
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
	for (auto itr = m_Sources.begin(); itr != m_Sources.end();)
	{
		delete (*itr);
		itr = m_Sources.erase(itr);
	}
}

bool SoundManager::IsFinished()
{
	return m_Done;
}
