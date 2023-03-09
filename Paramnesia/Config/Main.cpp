#include <PE/Utils.hpp>
#include <PE/Engine.hpp>

#include <iostream>
#include <fstream>

#define GAME_ONLY

// Temporary
#include "Temp/Paramnesia.hpp"

int main()
{
	pe::Engine engine;
	
	// The Game
	pa::Paramnesia p;

	// Loads the game
	/*
	std::ifstream myReadFile;
	myReadFile.open("Config/data.json");
	pe::StringBuilder dataStr;
	std::string aux;
	unsigned int count = 0;
	if (myReadFile.is_open()) {
		while (std::getline(myReadFile, aux)) {
			dataStr.append(aux);
		}
	}
	myReadFile.close();

	// Loads the game
	game.load(dataStr.toString());
	*/

	engine.setCurrentGame(p.game);

	// Will start the engine or the game
	#ifdef GAME_ONLY
	engine.startGame();
	#else
	engine.start();
	#endif

	return 0;
}