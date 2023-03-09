#include "AudioFile.hpp"

unsigned int pe::AudioFile::COUNT = 1;

pe::AudioFile::AudioFile(const char* path) : pe::Asset("Audiofile ", pe::AudioFile::COUNT++),
	m_buffer(sf::SoundBuffer())
{
	if (!m_buffer.loadFromFile(path))
		throw std::invalid_argument("Incorrect audio path!");
}

pe::AudioFile::~AudioFile()
{

}

const sf::SoundBuffer& pe::AudioFile::getSoundBuffer() const
{
	return m_buffer;
}