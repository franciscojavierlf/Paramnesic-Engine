#include "GameObject.hpp"
#include "PE/Asset/Scene.hpp"

unsigned int pe::GameObject::COUNT = 1;

pe::GameObject::GameObject(const char* name) : Asset(name), m_destroyed(false)
{

}

pe::GameObject::~GameObject()
{
	// Deletes all the components
	for (unsigned int i = 0; i < m_components.length(); i++)
		delete m_components.get(i);

	// Deletes all children
	for (unsigned int i = 0; i < m_children.length(); i++)
		delete m_children.get(i);
}

void pe::GameObject::setCurrentScene(const pe::Scene& scene)
{
	m_currentScene = &scene;
}

void pe::GameObject::addChild(const pe::GameObject& object)
{
	m_children.add(&object);
}

void pe::GameObject::addComponent(pe::GameComponent* const component)
{
	m_components.add(component);
}

pe::GameComponent* pe::GameObject::getComponent(const pe::String& name)
{
	return nullptr;
}

const pe::GameComponent* pe::GameObject::getComponent(const pe::String& name) const
{
	return nullptr;
}

pe::GameComponent* pe::GameObject::getComponent(const unsigned int& i)
{
	if (i >= m_components.length())
		throw std::out_of_range("Out of range");

	return m_components[i];
}

const pe::GameComponent* pe::GameObject::getComponent(const unsigned int& i) const
{
	if (i >= m_components.length())
		throw std::out_of_range("Out of range");

	return m_components[i];
}


unsigned int pe::GameObject::getComponentCount() const
{
	return m_components.length();
}

const pe::Scene* pe::GameObject::getCurrentScene() const
{
	return m_currentScene;
}

void pe::GameObject::destroy()
{
	m_destroyed = true;
}

const bool& pe::GameObject::isDestroyed() const
{
	return m_destroyed;
}

void pe::GameObject::setParent(const pe::GameObject& parent)
{
	m_parent = &parent;
}

// Method just for game object
void pe::GameObject::parentTick()
{
	tick();

	// Game components
	for (unsigned int i = 0; i < m_components.length(); i++)
		m_components.get(i)->tick();
}

// Gets called when hitbox collides with another
void pe::GameObject::onCollisionEnter2D(pe::GameObject& other)
{

}