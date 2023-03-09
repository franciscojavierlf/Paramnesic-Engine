#pragma once

#include "PE\GameObject\GameComponent\GameComponent.hpp"
#include "PE\Asset\SoundChannel.hpp"
#include "PE\Asset\AudioFile.hpp"

namespace pe
{
	class Audio final : public pe::GameComponent
	{
	public:
		Audio(pe::GameObject& object);
		~Audio() override;

		void setAudioFile(const pe::AudioFile& audioFile);
		void setSoundChannel(const pe::SoundChannel& soundChannel);
		void setVolume(float volume);
		void play();
		void pause();
		void restart();
		void stop();
		void loop(const bool& loop);
		
	private:
		sf::Sound m_sound;
		const pe::SoundChannel* m_channel;
	};
}