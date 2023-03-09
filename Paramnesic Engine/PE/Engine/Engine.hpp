#pragma once

#include "PE\Engine\Screen.hpp"
#include "PE\Game\Game.hpp"
#include "PE\Engine\UI\EnginePanel.hpp"
#include <thread>

namespace pe
{
	class Engine final
	{
	public:
		Engine();
		~Engine();

		void setCurrentGame(pe::Game& Game);

		// Starts the engine
		void start();
		// Stops the engine
		void stop();

		// Starts the game
		void startGame();
		// Stops the game
		void stopGame();


		// Engine
		void tick();
		void render();

		// Game
		void tickGame();
		void renderGame();

		// Main loop for the engine
		void run();

		// Main loop for the game
		void runGame();

	private:
		// The engine
		pe::Screen m_engineScreen;
		pe::Scene m_engineScene;
		bool m_engineRunning;

		// The game
		pe::Screen m_gameScreen;
		pe::Game* m_game;
		std::thread m_gameThread;
		bool m_gameRunning;
		bool m_gameThreadRunning;
	};
}