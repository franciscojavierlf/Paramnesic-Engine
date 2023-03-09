#pragma once

#include <SFML/Graphics/Font.hpp>
#include <PE/Utils/String.hpp>

namespace pe
{
	class Font final
	{
	public:
		Font();
		Font(const pe::String& path);
		~Font();

		void load(const pe::String& path);

		friend class TextRenderer;

	private:
		sf::Font m_font;
	};
}