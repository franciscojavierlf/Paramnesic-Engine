#include "BoxCollider2D.hpp"

pe::BoxCollider2D::BoxCollider2D(pe::GameObject& object) : GameComponent(object, false)
{
	// Sets the size of the sprite if the object has one
	pe::SpriteRenderer* const sprite = (pe::SpriteRenderer*) object.getComponent("SpriteRenderer");
	if (sprite) this->setSize(sprite->getSpriteWidth(), sprite->getSpriteHeight());
	else this->setSize(16, 16);

	this->setOffset(object.transform.position.x, object.transform.position.y);
}

pe::BoxCollider2D::~BoxCollider2D()
{

}

void pe::BoxCollider2D::setSize(const float& width, const float& height)
{
	m_size.x = width;
	m_size.y = height;
}

void pe::BoxCollider2D::setOffset(const float& x, const float& y)
{
	m_offset.x = x;
	m_offset.y = y;
}

void pe::BoxCollider2D::tick()
{
	//checkCollision();
}

/*

bool Hitbox::collides(sf::Vector2f vector)
{
	return rect.collides(vector);
}

bool Hitbox::collides(Hitbox* other)
{
	return rect.collidesRectangle(other->rect);
}

void pe::BoxCollider2D::checkCollision()
{
	std::vector<GameObject*> objects = object.getScene()->getGameObjectsIn
	(rectangle, object);

	for (GameObject* other : objects)
	{
		Hitbox* box = other->getHitbox();
		if (box != nullptr && this->collides(box))
			object->onHitboxEnter(box);
	}
}
*/