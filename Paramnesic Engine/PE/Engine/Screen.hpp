#pragma once

#include <SFML\Graphics.hpp>
#include "PE/Asset/Scene.hpp"
#include "PE/Utils/String.hpp"
#include "PE/GameObject.hpp"

namespace pe
{
	class Screen final
	{
	public:
		Screen();
		Screen(const pe::String& title);
		~Screen();

		bool isOpened() const;
		void open();
		void close();

		// Clears the screen
		void clear();
		// Renders a whole scene
		void render(const pe::Scene& scene);
		// Displays the rendered scene
		void display();

		bool pollEvent(sf::Event& event);
		void setView(const sf::View& view);
		
	private:
		// Game Objects
		void render(const pe::GameObject& gameObject);

		// Game Components
		void render(const pe::TextRenderer* text);
		/*
		void render(const pe::Scene& scene);
		void render(const pe::TileMap&, sf::Vector2f);
		void render(const pe::SpriteRenderer&, sf::Vector2f);
		void draw(sf::RenderTarget&, sf::RenderStates);
		*/

	private:
		sf::RenderWindow m_window;
		pe::String m_title;
	};
}