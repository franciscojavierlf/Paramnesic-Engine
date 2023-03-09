#pragma once

namespace pe
{
	struct GameGraphics final
	{
	public:
		unsigned short windowWidth;
		unsigned short windowHeight;

	private:
		GameGraphics();

		friend struct GameSettings;
	};
}