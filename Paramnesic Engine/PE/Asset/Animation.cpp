#include "Animation.hpp"

unsigned int pe::Animation::COUNT = 1;

pe::Animation::Animation() : pe::Asset("animation " + pe::Animation::COUNT++),
	m_time(0.0f), m_frame(0), m_speed(0.0f), m_playing(false)
{
}

pe::Animation::~Animation()
{

}

void pe::Animation::setSpeed(const float& speed)
{
	m_speed = speed;
}


void pe::Animation::play()
{
	m_playing = true;
}

void pe::Animation::pause()
{
	m_playing = false;
}

void pe::Animation::restart()
{
	m_frame = 0;
	m_time = 0.0f;
}

void pe::Animation::stop()
{
	pause();
	restart();
}

void pe::Animation::tick()
{
	if (m_playing)
	{
		m_time++;

		// Error
		if (m_time > 60000) m_time = 0.0f;

		// For cool animation
		if (m_time == 1.0f)
			m_frame++;
		/*
		if (m_time % m_speed == 0)
			if (m_frame >= msprites.size() - 1) frame = 0;
			else frame++;
			*/
	}
	else
	{
		m_time = 0;
		m_frame = 0;
	}
}