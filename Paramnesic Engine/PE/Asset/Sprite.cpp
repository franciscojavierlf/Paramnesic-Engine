#include "Sprite.hpp"

unsigned int pe::Sprite::COUNT = 1;

pe::Sprite::Sprite(const pe::Color& color, const float& width, const float& height) :
	pe::Asset("Sprite ", pe::Sprite::COUNT++)
{
	m_sprite.setColor(sf::Color::Red);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 1, 1));
	m_sprite.setScale(sf::Vector2f(width, height));
}


pe::Sprite::Sprite(const char* path) : pe::Asset("Sprite ", pe::Sprite::COUNT++)
{
	sf::Texture texture;

	if (!texture.loadFromFile(path))
		throw std::invalid_argument("Incorrect sprite path!");

	m_sprite.setTexture(texture);
}

pe::Sprite::~Sprite()
{

}

const float& pe::Sprite::getWidth() const
{
	return m_sprite.getScale().x;
}

const float& pe::Sprite::getHeight() const
{
	return m_sprite.getScale().y;
}

/*
sf::Sprite* Sprite::getDrawable()
{
	return &sprite;
}

sf::Vector2f Sprite::getSize()
{
	return sprite.getScale();
}

oid SpriteSheet::divideSprites(Sprite& sheet)
{
	float xPos;
	float yPos;

	for (unsigned int y = 0; y < spriteSize.y; y++)
		for (unsigned int x = 0; x < spriteSize.x; x++)
		{
			xPos = (float)x * spriteSize.x;
			yPos = (float)y * spriteSize.y;

			// Gets the partial sprite of the sprite sheet and inserts it
			sprites.push_back(&(sheet.getPartialSprite)(Rectangle
			(sf::Vector2f(xPos, yPos),
				sf::Vector2f((float)spriteSize.x, (float)spriteSize.y))));
		}
}
*/