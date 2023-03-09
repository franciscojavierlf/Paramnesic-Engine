#include "TileMap.hpp"

pe::TileMap::TileMap(pe::GameObject& object, const unsigned int& width, const unsigned int& height,
					const float& tileWidth, const float& tileHeight)
	: pe::GameComponent(object, false), m_width(width), m_height(height), 
	m_tileSize(pe::Vector2(tileWidth, tileHeight)), m_tiles(pe::ArrayList<pe::Tile*>(m_width * m_height))
{

}

pe::TileMap::~TileMap()
{
}

const unsigned int& pe::TileMap::getWidth() const
{
	return m_width;
}

const unsigned int& pe::TileMap::getHeight() const
{
	return m_height;
}

const float& pe::TileMap::getTileWidth() const
{
	return m_tileSize.x;
}
const float& pe::TileMap::getTileHeight() const
{
	return m_tileSize.y;
}

void pe::TileMap::setSize(const unsigned int& width, const unsigned int& height)
{
	m_width = width;
	m_height = height;
}

void pe::TileMap::setTileSize(const float& tileWidth, const float& tileHeight)
{
	m_tileSize.x = tileWidth;
	m_tileSize.y = tileHeight;
}

const pe::Tile& pe::TileMap::getTileAt(const unsigned int& x, const unsigned int& y)
{
	return *m_tiles.get(x + y * m_width);
}