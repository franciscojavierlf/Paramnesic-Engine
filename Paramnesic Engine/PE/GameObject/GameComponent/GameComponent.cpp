#include "GameComponent.hpp"

pe::GameComponent::GameComponent(pe::GameObject& object, bool multiplicable) : m_object(object), 
	m_multiplicable(multiplicable)
{
}

pe::GameComponent::~GameComponent()
{

}

const bool& pe::GameComponent::isMultiplicable() const
{
	return m_multiplicable;
}

void pe::GameComponent::tick()
{

}