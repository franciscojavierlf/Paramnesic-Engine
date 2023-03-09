#pragma once

#include "PE\Game\GameGraphics.hpp"

namespace pe
{
	struct GameSettings final
	{
	public:
		pe::GameGraphics graphics;

	private:
		GameSettings();

		friend class Game;
	};
}