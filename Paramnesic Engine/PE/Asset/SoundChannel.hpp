#pragma once

#include "PE\Asset\Asset.hpp"

namespace pe
{
	class SoundChannel final : public pe::Asset
	{
	public:
		SoundChannel();
		~SoundChannel();

	private:
		static unsigned int COUNT;
		float m_volume;
	};
}