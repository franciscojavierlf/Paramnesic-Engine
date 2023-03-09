#pragma once

#include "PE\GameObject\GameComponent\GameComponent.hpp"
#include "PE\Asset\Sprite.hpp"

namespace pe
{
	class SpriteRenderer final : public pe::GameComponent
	{

	public:
		SpriteRenderer(pe::GameObject& object);
		~SpriteRenderer() override;

		const float& getSpriteWidth() const;
		const float& getSpriteHeight() const;
		void setSprite(const pe::Sprite& sprite);

	private:
		const pe::Sprite* m_sprite;
	};
}