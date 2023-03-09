#pragma once

#include <SFML/Graphics/Text.hpp>
#include "PE/Graphics/Font.hpp"
#include "PE/Utils/Color.hpp"
#include "PE/GameObject/GameComponent/GameComponent.hpp"

namespace pe
{
	class TextRenderer : public pe::GameComponent
	{
	public:
		TextRenderer(pe::GameObject& object);
		~TextRenderer() override;

		void setFont(const pe::Font& font);
		void setText(const pe::String& text);
		void setSize(const unsigned char& size);
		void setColor(const pe::Color& color);

	private:
		friend class Screen;

	private:
		pe::String m_text;
		pe::Font m_font;
		unsigned short m_size;
		pe::Color m_color;

	private:
		sf::Text m_sftext;
	};
}