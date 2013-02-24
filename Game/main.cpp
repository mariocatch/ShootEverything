#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <chrono>
#include <thread>

#include "Cursor.h"
#include "Player.h"
#include "Game.h"

int main()
{
	// Window setup.
	sf::RenderWindow gameWindow(sf::VideoMode(1024, 768), "ShootEverything", 1);
	gameWindow.setVerticalSyncEnabled(true);
	gameWindow.setMouseCursorVisible(false);

	// Frame timing.
	sf::Clock gameClock;
	sf::Event gameEvents;
	float gameTime = 0;

	// Background.
	sf::Texture bgTexture;
	bgTexture.loadFromFile("Assets/spaceBackground.png");
	sf::Sprite bgSprite;
	bgSprite.setTexture(bgTexture);

	// Create Entities.
	Player player(
		new DrawableComponent(gameWindow, "Assets/spaceman.png"), 
		new PositionComponent(sf::Vector2f(10, 700)),
		new PlayerInputComponent(),
		new MovableComponent(sf::Vector2f(150, 150)));

	Cursor customCursor(
		new DrawableComponent(gameWindow, "Assets/spaceCursor.png"), 
		new PositionComponent(sf::Vector2f(0, 0)),
		new MouseComponent());

	// Add Entities to game manager.
	Game::getInstance()->addEntity(player);
	Game::getInstance()->addEntity(customCursor);

	// Game loop.
	while (gameWindow.isOpen())
	{
		while (gameWindow.pollEvent(gameEvents)) 
		{
			// Close game on Escape.
			if ((gameEvents.type == sf::Event::KeyPressed && gameEvents.key.code == sf::Keyboard::Escape) || (gameEvents.type == sf::Event::Closed))
			{
				gameWindow.close();
			}
		}

		// Draw background.
		gameWindow.draw(bgSprite);

		// Update/Draw each Entity.
		std::list<Entity*>::iterator entityIter = Game::getInstance()->getEntities().begin();
		for(entityIter; entityIter != Game::getInstance()->getEntities().end(); entityIter++)
		{
			(*entityIter)->update(gameTime);
			(*entityIter)->draw();
		}

		gameWindow.display();
		gameWindow.clear(sf::Color::White);

		gameTime = gameClock.restart().asSeconds();

		// Frame.
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

	} // End window is open

	Game::getInstance()->shutdown();

	return 0;
}