#pragma once

#include <SFML\Graphics.hpp>
#include "PE\Asset\Asset.hpp"
#include "PE/Utils/Color.hpp"

namespace pe
{
	class Sprite final : public pe::Asset
	{
	public:
		Sprite(const pe::Color& color, const float& width, const float& height);
		Sprite(const char* path);
		~Sprite() override;

		const float& getWidth() const;
		const float& getHeight() const;

	private:
		static unsigned int COUNT;
		sf::Sprite m_sprite;
		pe::ArrayList<pe::Sprite*> m_childSprites;
	};
}