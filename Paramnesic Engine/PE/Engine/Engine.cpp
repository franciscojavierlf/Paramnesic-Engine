#include "Engine.hpp"

pe::Engine::Engine()
{
}

pe::Engine::~Engine()
{
}

void pe::Engine::setCurrentGame(pe::Game& game)
{
	m_game = &game;
}

void pe::Engine::tick()
{
	m_engineScene.tick();
}

void pe::Engine::render()
{
	m_engineScreen.clear();

	m_engineScreen.render(m_engineScene);

	m_engineScreen.display();
}

void pe::Engine::start()
{
	pe::EnginePanel* panel = new pe::EnginePanel();
	m_engineScene.addObject(panel);

	m_engineRunning = true;
	run();
}

void pe::Engine::stop()
{
	stopGame();
	m_engineRunning = false;
}

void pe::Engine::run()
{
	// Opens the window
	m_engineScreen.open();

	sf::Clock clock;
	int fps = 0;

	sf::Int32 timer = clock.getElapsedTime().asMilliseconds();
	sf::Int64 lastTime = clock.getElapsedTime().asMicroseconds();
	const double ns = 1000000.0 / 60.0;
	sf::Int64 currentTime = 0;
	double delta = 0;
	int frames = 0;
	int ticks = 0;

	while (m_engineRunning)
	{
		sf::Event event;
		while (m_engineScreen.pollEvent(event))
		{
			//if (event.type == sf::Event::Resized)
			//m_engineScreen.setView(sf::View(sf::FloatRect(0.0f, 0.0f, event.size.width / 4.0f, event.size.height / 4.0f)));
			if (event.type == sf::Event::Closed)
			{
				m_engineRunning = false;
				m_engineScreen.close();
			}

		}

		currentTime = clock.getElapsedTime().asMicroseconds();
		delta += (currentTime - lastTime) / ns;
		lastTime = currentTime;

		while (delta >= 1)
		{
			tick();
			ticks++;
			delta--;
		}

		render();
		frames++;

		if (clock.getElapsedTime().asMilliseconds() - timer > 1000)
		{
			timer += 1000;
			ticks = frames = 0;
		}
	}

	// Stops game and waits until it ends
	stopGame();

	std::cout << "Engine running ended." << std::endl;
}

void pe::Engine::tickGame()
{
	if (m_game->m_currentScene != nullptr)
		m_game->m_currentScene->tick();
}

void pe::Engine::renderGame()
{
	m_gameScreen.clear();

	if (m_game->m_currentScene != nullptr)
		m_gameScreen.render(*m_game->m_currentScene);

	m_gameScreen.display();
}

void pe::Engine::startGame()
{
	if (m_game != nullptr)
	{
		m_gameRunning = true;
		// Starts thread
		m_gameThreadRunning = true;
		m_gameThread = std::thread(&pe::Engine::runGame, this);

		// If the engine didn't start first
		if (!m_engineRunning)
			m_gameThread.join();
	}
	else pe::Exception("There is no game loaded!");
}

void pe::Engine::stopGame()
{
	m_gameRunning = false;

	// Only waits for thread if it is running
	if (m_gameThreadRunning)
		m_gameThread.join();
	m_gameThreadRunning = false;
}

void pe::Engine::runGame()
{
	if (m_game == nullptr)
	{
		std::cout << "There is no Game loaded!" << std::endl;
	}
	else
	{
		// Opens the window
		m_gameScreen.open();

		sf::Clock clock;
		int fps = 0;

		sf::Int32 timer = clock.getElapsedTime().asMilliseconds();
		sf::Int64 lastTime = clock.getElapsedTime().asMicroseconds();
		const double ns = 1000000.0 / 60.0;
		sf::Int64 currentTime = 0;
		double delta = 0;
		int frames = 0;
		int ticks = 0;

		while (m_gameRunning)
		{
			sf::Event event;
			while (m_gameScreen.pollEvent(event))
			{
				if (event.type == sf::Event::Resized)
					m_gameScreen.setView(sf::View(sf::FloatRect(0.0f, 0.0f, event.size.width / 4.0f, event.size.height / 4.0f)));
				if (event.type == sf::Event::Closed)
				{
					m_gameRunning = false;
					m_gameScreen.close();
				}

			}

			currentTime = clock.getElapsedTime().asMicroseconds();
			delta += (currentTime - lastTime) / ns;
			lastTime = currentTime;

			while (delta >= 1)
			{
				tickGame();
				ticks++;
				delta--;
			}

			renderGame();
			frames++;

			if (clock.getElapsedTime().asMilliseconds() - timer > 1000)
			{
				timer += 1000;
				std::cout << ticks << " ticks, " << frames << " fps" << std::endl;
				ticks = frames = 0;
			}
		}
	}

	std::cout << "Game running ended." << std::endl;
}