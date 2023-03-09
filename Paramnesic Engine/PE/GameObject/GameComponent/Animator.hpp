#pragma once

#include "PE\GameObject\GameComponent\GameComponent.hpp"
#include "PE\Asset\Animation.hpp"
#include "PE/Utils/Map.hpp"

namespace pe
{
	class Animator final : public GameComponent
	{
	public:
		Animator(pe::GameObject& object);
		~Animator() override;

		void setCurrentAnimation(const char* animation);

		/*
		void play();
		void pause();
		void restart();
		void stop();
		void tick();
		*/
		
	private:
		Map<pe::String, pe::Animation*> m_animations;
	};
}