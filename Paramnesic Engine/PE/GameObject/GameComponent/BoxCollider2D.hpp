#pragma once

#include "PE\GameObject\GameComponent\GameComponent.hpp"
#include "PE/GameObject/GameObject.hpp"
#include "PE\GameObject\GameComponent\SpriteRenderer.hpp"
#include "PE\Utils\Transform.hpp"

namespace pe
{
	class BoxCollider2D final : public pe::GameComponent
	{
	public:
		BoxCollider2D(pe::GameObject& object);
		~BoxCollider2D() override;
		void setSize(const float& width, const float& height);
		void setOffset(const float& width, const float&  height);

	private:
		void tick() override;

		friend class GameObject;

		//bool collides(const pe::BoxCollider2D& other);
		//void checkCollision();

	private:
		pe::Vector2 m_size;
		pe::Vector2 m_offset;
	};
}