#include <PE/Graphics/Font.hpp>

pe::Font::Font()
{
	load("res/fonts/arial.TTF");
}

pe::Font::Font(const pe::String& path)
{
	load(path);
}

pe::Font::~Font()
{

}

void pe::Font::load(const pe::String& path)
{
	m_font.loadFromFile(path);
}