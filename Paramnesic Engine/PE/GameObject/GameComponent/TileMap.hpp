#pragma once

#include "PE\GameObject\GameComponent\GameComponent.hpp"
#include "PE\Asset\Tile.hpp"
#include "PE/Utils/Vector2.hpp"

namespace pe
{
	class TileMap final : public pe::GameComponent
	{
	public:
		TileMap(pe::GameObject& object, const unsigned int& width = 16, const unsigned int& height = 16,
			const float& tileWidth = 16, const float& tileHeight = 16);
		~TileMap() override;

		const unsigned int& getWidth() const;
		const unsigned int& getHeight() const;
		const float& getTileWidth() const;
		const float& getTileHeight() const;
		void setSize(const unsigned int& width, const unsigned int& height);
		void setTileSize(const float& tileWidth, const float& tileHeight);
		const pe::Tile& getTileAt(const unsigned int& x, const unsigned int& y);

	private:
		unsigned int m_width;
		unsigned int m_height;
		pe::Vector2 m_tileSize;
		pe::ArrayList<pe::Tile*> m_tiles;
	};
}