#include "PA/Entity/Entity.hpp"

pa::Entity::Entity(const pe::String& name) : m_name(name)
{
	this->addComponent(new pe::SpriteRenderer(*this));
}

pa::Entity::~Entity()
{

}