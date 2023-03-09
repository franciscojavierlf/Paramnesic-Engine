#include "SpriteRenderer.hpp"

pe::SpriteRenderer::SpriteRenderer(pe::GameObject& object) : pe::GameComponent(object, false)
{

}

pe::SpriteRenderer::~SpriteRenderer()
{

}

const float& pe::SpriteRenderer::getSpriteWidth() const
{
	return m_sprite->getWidth();
}

const float& pe::SpriteRenderer::getSpriteHeight() const
{
	return m_sprite->getHeight();
}

void pe::SpriteRenderer::setSprite(const pe::Sprite& sprite)
{
	m_sprite = &sprite;
}