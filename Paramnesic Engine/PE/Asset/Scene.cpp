#include "Scene.hpp"

unsigned int pe::Scene::COUNT = 1;

pe::Scene::Scene() : Asset("Scene ", pe::Scene::COUNT++)
{
}

pe::Scene::~Scene()
{
}

/*
// Gets the game objects in the given area without the exception
pe::ArrayList<pe::GameObject&> pe::Scene::getGameObjectsIn(const pe::Vector2& p0, const pe::Vector2& p1, const pe::String& exception) const
{
	pe::ArrayList<pe::GameObject&> list;
	pe::GameObject* const obj;

	for (unsigned int i = 0; i < m_objects.length(); i++)
	{
		obj = m_objects.get(i);
		if (obj->getName() != exception)
			if (obj->.getC)
				list.push_back(obj);
	}

	return list;
}

*/

pe::Asset* pe::Scene::getAsset(const pe::String& path)
{
	// Can throw an error if it does not exist
	return m_assetsBuffer.getAsset(path);
}

void pe::Scene::addObject(pe::GameObject* const object)
{
	m_objects.add(object->getName(), object);

	// Loads all the assets of the game object
	//object->load(m_assetsBuffer);
}

unsigned int pe::Scene::getObjectCount() const
{
	return m_objects.length();
}

pe::GameObject* pe::Scene::getObjectAt(const unsigned int& i)
{
	if (i >= m_objects.length())
		throw std::out_of_range("Index out of range.");

	return m_objects.objectAt(i);
}

const pe::GameObject* pe::Scene::getObjectAt(const unsigned int& i) const
{
	if (i >= m_objects.length())
		throw std::out_of_range("Index out of range.");

	return m_objects.objectAt(i);
}

pe::GameObject* pe::Scene::getObject(const pe::String& name)
{
	return m_objects[name];
}

const pe::GameObject* pe::Scene::getObject(const pe::String& name) const
{
	return m_objects[name];
}

void pe::Scene::tick()
{
	pe::GameObject* curr;

	// Organizes the game objects

	// Updates the game objects
	for (unsigned int i = 0; i < m_objects.length(); i++)
	{
		curr = m_objects.objectAt(i);
		// ParentTick also calls tick function
		curr->parentTick();

		// Destroys the game object
		if (curr->isDestroyed())
			m_objects.removeAt(i);
	}
}