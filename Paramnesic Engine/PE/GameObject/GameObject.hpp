#pragma once

#include "PE/Asset/AssetsBuffer.hpp"
#include "PE/Utils/Transform.hpp"
#include "PE/GameObject/GameComponent/GameComponent.hpp"
// Includes Scene.hpp in cpp file

namespace pe
{
	struct Transform;
	class Scene;

	class GameObject : public pe::Asset
	{
	public:
		GameObject(const char* name);
		~GameObject() override;

		void destroy();
		const bool& isDestroyed() const;
		void setCurrentScene(const pe::Scene& scene);
		void addChild(const pe::GameObject& child);
		void addComponent(pe::GameComponent* const component);
		pe::GameComponent* getComponent(const pe::String& name);
		pe::GameComponent* getComponent(const unsigned int& i);
		const pe::GameComponent* getComponent(const pe::String& name) const;
		const pe::GameComponent* getComponent(const unsigned int& i) const;
		unsigned int getComponentCount() const;

	protected:
		const pe::Scene* getCurrentScene() const;

	private:
		void setParent(const pe::GameObject& parent);

		void parentTick();

		//void load(const pe::AssetsBuffer& assetsBuffer); // Will be called when a scene loads the game object

		virtual void onCollisionEnter2D(pe::GameObject& other);
		virtual void tick() = 0;

		friend class Scene;

	public:
		pe::Transform transform;

	private:
		static unsigned int COUNT;

		bool m_destroyed;
		const pe::Scene* m_currentScene;
		const pe::GameObject* m_parent;
		pe::ArrayList<const pe::GameObject*> m_children;
		pe::ArrayList<pe::GameComponent*> m_components;
	};
}