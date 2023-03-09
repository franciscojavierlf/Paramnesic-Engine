#include "SoundChannel.hpp"

unsigned int pe::SoundChannel::COUNT = 1;

pe::SoundChannel::SoundChannel() : pe::Asset("SoundChannel ", pe::SoundChannel::COUNT++), m_volume(0.0f)
{

}

pe::SoundChannel::~SoundChannel()
{

}