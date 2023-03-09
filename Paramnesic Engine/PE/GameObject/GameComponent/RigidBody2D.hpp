#pragma once

#include "PE\GameObject\GameComponent\GameComponent.hpp"
#include "PE/Utils/Vector2.hpp"

namespace pe
{
	class RigidBody2D final : public pe::GameComponent
	{
	public:
		RigidBody2D(pe::GameObject& object);
		~RigidBody2D() override;

		void movePosition(const pe::Vector2& position);

	private:
		void tick();

		friend class GameObject;

	private:
		pe::Vector2 m_speed;
		float m_gravity;
		float m_gravity_z;
	};
}