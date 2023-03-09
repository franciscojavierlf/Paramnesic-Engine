#pragma once

#include "PE\Asset\Asset.hpp"
#include "PE/GameObject/GameObject.hpp"
#include "PE/Asset/AssetsBuffer.hpp"

namespace pe
{
	// This class will manage memory so that there is no overflow.
	class Scene final : public pe::Asset
	{
	public:
		Scene();
		~Scene() override;

		// Manages the loaded assets
		pe::Asset* getAsset(const pe::String& path);
		//pe::ArrayList<pe::GameObject&> getGameObjectsIn(const pe::Vector2& p0, const pe::Vector2& p1, const pe::String& exception) const;
		void addObject(pe::GameObject* const object);
		unsigned int getObjectCount() const;
		pe::GameObject* getObjectAt(const unsigned int& i);
		const pe::GameObject* getObjectAt(const unsigned int& i) const;
		pe::GameObject* getObject(const pe::String& name);
		const pe::GameObject* getObject(const pe::String& name) const;

		void tick();

	private:
		static unsigned int COUNT;
		pe::Map<pe::String, pe::GameObject*> m_objects;

		// Will manage the loaded assets in memory
		pe::AssetsBuffer m_assetsBuffer;
	};
}