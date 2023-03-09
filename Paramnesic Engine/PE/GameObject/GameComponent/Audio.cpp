#include "Audio.hpp"

pe::Audio::Audio(pe::GameObject& object) : pe::GameComponent(object, true), m_channel(false)
{

}

pe::Audio::~Audio()
{

}

void pe::Audio::setAudioFile(const pe::AudioFile& audioFile)
{
	m_sound.setBuffer(audioFile.getSoundBuffer());
}

void pe::Audio::setSoundChannel(const pe::SoundChannel& channel)
{
	m_channel = &channel;
}

void pe::Audio::setVolume(float volume)
{
	if (m_channel)
		std::cout << "Taking volume from a channel.";
	else
		m_sound.setVolume(volume);
}

void pe::Audio::play()
{
	m_sound.play();
}

void pe::Audio::pause()
{
	m_sound.pause();
}

void pe::Audio::restart()
{
	stop();
	play();
}

void pe::Audio::stop()
{
	m_sound.stop();
}

void pe::Audio::loop(const bool& loop)
{
	m_sound.setLoop(loop);
}