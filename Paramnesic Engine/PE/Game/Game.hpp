#pragma once

#include "PE\Asset\Scene.hpp"
#include "PE\Game\GameSettings.hpp"
#include "PE\Utils.hpp"

namespace pe
{
	// This class will have the references of the assets, so that you can see
	// what's in the game. The scene will be the one who manages memory.
	class Game final
	{
	public:
		Game();
		~Game();

		pe::String getName() const;
		void setName(const char* name);
		void addAssetReference(const pe::String& reference);
		pe::String getAssetReference(const unsigned int& i);
		unsigned int getAssetReferencesCount() const;

		const pe::Scene& getCurrentScene() const;
		pe::String getSaveString();
		void load(const pe::String& jsonString);

	private:
		friend class Engine;

	public:
		pe::GameSettings settings;

	private:
		pe::Scene* m_currentScene;
		pe::String m_name;
		pe::ArrayList<pe::String> m_assetPaths;

	};
}