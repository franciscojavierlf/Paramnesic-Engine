#pragma once

#include <PE/Game.hpp>
#include <PE/GameObject.hpp>
#include <PE/Asset.hpp>

/*
	Temporary file. Will load from a JSON.

	How it goes. The assests exist only in a Json file, not in the memory
	(to avoid high memory usage). When you load a scene, you will load all the assets
	that are in the scene, but only that. Thus, you should always have just a reference
	of what the game really has, but no load everything at once.
*/

namespace pa
{
	class Paramnesia
	{
	public:
		Paramnesia();
		~Paramnesia();

	public:
		pe::Game game;
	};
}