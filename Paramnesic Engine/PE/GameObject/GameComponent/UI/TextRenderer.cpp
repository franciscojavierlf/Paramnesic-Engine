#include "PE/GameObject/GameComponent/UI/TextRenderer.hpp"

pe::TextRenderer::TextRenderer(pe::GameObject& object) : pe::GameComponent(object, false)
{
	setFont(m_font);
	setText("Text");
}

pe::TextRenderer::~TextRenderer()
{

}

void pe::TextRenderer::setFont(const pe::Font& font)
{
	m_font = font;
	m_sftext.setFont(m_font.m_font);
}

void pe::TextRenderer::setText(const pe::String& text)
{
	m_sftext.setString(text);
}

void pe::TextRenderer::setSize(const unsigned char& size)
{

}

void pe::TextRenderer::setColor(const pe::Color& color)
{

}

/*
pe::TextScript::TextScript(pe::GameObject& object) : pe::GameComponent(object, true)
{
	if (!font.loadFromFile("default_font.ttf"))
		throw std::invalid_argument("Font not available!");

	text.setFont(font);
	text.setCharacterSize(16);

	text.setString("string");
}

pe::TextScript::~TextScript()
{

}

/*

void DrawableComponentText::setSize(sf::Vector2f scale)
{
text.setScale(scale);
}

sf::Vector2f DrawableComponentText::getSize()
{
sf::FloatRect rect = text.getGlobalBounds();

return sf::Vector2f(rect.width, rect.height);
}

void DrawableComponentText::setSmooth(bool smooth)
{
const_cast<sf::Texture&>(font.getTexture(text.getCharacterSize())).setSmooth(false);
}

void DrawableComponentText::setPosition(sf::Vector2f position)
{
// Strange offset to place the y origin in 0
position.y -= getSize().y + getSize().y / 3.5;

text.setPosition(position);
}

void DrawableComponentText::setColor(sf::Color color)
{
text.setFillColor(color);
}

void DrawableComponentText::setString(std::string string)
{
text.setString(string);
}

void DrawableComponentText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
target.draw(text);
}
*/