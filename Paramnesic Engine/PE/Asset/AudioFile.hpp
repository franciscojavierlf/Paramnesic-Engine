#pragma once

#include <SFML\Audio.hpp>
#include "PE\Asset\Asset.hpp"

namespace pe
{
	class AudioFile final : public pe::Asset
	{
	public:
		AudioFile(const char* path);
		~AudioFile() override;

		const sf::SoundBuffer& getSoundBuffer() const;

	private:
		static unsigned int COUNT;
		sf::SoundBuffer m_buffer;
	};
}