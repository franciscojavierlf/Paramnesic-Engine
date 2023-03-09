#include "Screen.hpp"

pe::Screen::Screen() : pe::Screen("")
{

}

pe::Screen::Screen(const pe::String& title) : m_title(title)
{

}

pe::Screen::~Screen()
{

}

bool pe::Screen::isOpened() const
{
	return m_window.isOpen();
}

void pe::Screen::open()
{
	m_window.create(sf::VideoMode(1200, 800),
		m_title, sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
}

void pe::Screen::close()
{
	m_window.close();
}

void pe::Screen::clear()
{
	m_window.clear();
}

void pe::Screen::display()
{
	m_window.display();
}

bool pe::Screen::pollEvent(sf::Event& event)
{
	return m_window.pollEvent(event);
}

void pe::Screen::setView(const sf::View& view)
{
	m_window.setView(view);
}


void pe::Screen::render(const pe::Scene& scene)
{
	for (unsigned int i = 0; i < scene.getObjectCount(); i++)
		render(*scene.getObjectAt(i));
}

void pe::Screen::render(const pe::GameObject& object)
{
	const char* className;
	const pe::GameComponent* component;
	for (unsigned int i = 0; i < object.getComponentCount(); i++)
	{
		component = object.getComponent(i);
		className = typeid(*component).name();

		// The cases
		if (pe::String::stringEqualsTo(className, "class pe::TextRenderer"))
			render((const pe::TextRenderer*)component);
	}
}

void pe::Screen::render(const pe::TextRenderer* text)
{
	m_window.draw(text->m_sftext);
}

/*
void pe::Screen::render(TileMap* map)
{
	sf::Vector2u size = map->getSize();

	// Just accesses the tiles within the camera
	unsigned int xa, ya, xx, yy;
	unsigned int tileSize = map->getTileSize();
	if (camera->position.x < 0) xa = 0;
	else xa = (unsigned int) camera->position.x / tileSize;
	if (camera->position.y < 0) ya = 0;
	else ya = (unsigned int)camera->position.y / tileSize;

	// Handles errors with some resolutions
	xx = camera->getSize().x / tileSize;
	if (xx < size.x - 1) xx++;
	yy = camera->getSize().y / tileSize;
	if (yy < size.y - 1) yy++;

	for (unsigned int y = ya; y <= ya + yy; y++)
		for (unsigned int x = xa; x <= xa + xx; x++)
		{
			unsigned int tileCode = map->getTileCodeAt(x + y * size.x);
			render(map->getTile(tileCode), sf::Vector2f(x * (float) map->getTileSize(),
				y * (float) map->getTileSize()));
		}
}

void pe::Screen::render(Tile* tile, sf::Vector2f position)
{
	render(tile->getSprite(), position);
}

// HORRIBLY OPTIMIZED
void Screen::render(Sprite* sprite, sf::Vector2f position)
{
	// If the object is inside the camera
	if (isObjectInCamera(position, sprite->getSize()))
	{
		// Adjusts to camera angle
		position.x -= camera->position.x;
		position.y -= camera->position.y;

		sprite->getDrawable()->setPosition(position);
		m_window->draw(*(sprite->getDrawable()));
	}
}

bool Screen::isObjectInCamera(sf::Vector2f position, sf::Vector2f size)
{
	return !(position.x + size.x < camera->position.x ||
		position.x > camera->position.x + camera->getSize().x ||
		position.y + size.y < camera->position.y || 
		position.y > camera->position.y + camera->getSize().y);
}
*/