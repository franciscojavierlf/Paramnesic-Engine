#pragma once

#include "PE\Asset\Asset.hpp"

namespace pe
{
	class Animation final : public pe::Asset
	{
	public:
		Animation();
		~Animation() override;

		void setSpeed(const float& speed);
		void play();
		void pause();
		void restart();
		void stop();

		void tick();

	private:
		static unsigned int COUNT;
		unsigned int m_frame;
		float m_time;
		float m_speed;
		bool m_playing;
	};
}