#include "Game.hpp"

pe::Game::Game()
{
	
}

pe::Game::~Game()
{

}

pe::String pe::Game::getName() const
{
	return m_name;
}

void pe::Game::setName(const char* name)
{
	m_name = name;
}

const pe::Scene& pe::Game::getCurrentScene() const
{
	return *m_currentScene;
}

pe::String pe::Game::getSaveString()
{
	return pe::String();
}

void pe::Game::load(const pe::String& jsonString)
{

}