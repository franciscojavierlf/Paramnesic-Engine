#pragma once

#include "PE/Utils/Map.hpp"
#include "PE/Asset/Asset.hpp"
#include "PE/Utils/File.hpp"
#include "PE/Utils/Exceptions/FileNotFoundException.hpp"

#include "PE/Asset/Sprite.hpp"

namespace pe
{
	class AssetsBuffer final
	{
	public:
		AssetsBuffer();
		~AssetsBuffer();

		// Gets the asset, and if it is not loaded, then it will be. If it doesn't exist,
		// it sends and error.
		pe::Asset* getAsset(const pe::String& path);
		// Gets the asset, but if it is not loaded it sends a message.
		const pe::Asset* getAsset(const pe::String& path) const;

	private:
		// Loads an asset to the memory
		pe::Asset* loadAsset(const pe::String& path);
		// Removes an asset from the memory
		void unloadAsset(const pe::String& path);

		// Loads an specific asset
		pe::Sprite* loadSprite(const pe::Json assetJson);

	private:
		pe::Map<pe::String, pe::Asset*> m_loadedAssets;
	};
}