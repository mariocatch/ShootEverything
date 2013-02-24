#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <chrono>
#include <thread>

#include "Game.h"
#include "Cursor.h"
#include "Player.h"

int main()
{
	Game::getInstance()->start();

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
	Cursor customCursor(
		new DrawableComponent("Assets/spaceCursor.png"), 
		new PositionComponent(sf::Vector2f(0, 0)),
		new MouseComponent());

	Player player(
		new DrawableComponent("Assets/spaceman.png"), 
		new PositionComponent(sf::Vector2f(10, 700)),
		new PlayerInputComponent(),
		new MovableComponent(sf::Vector2f(150, 150)),
		new MouseComponent(),
		new GunComponent());

	// Add Entities to game manager.
	Game::getInstance()->addEntity(&player);
	Game::getInstance()->addEntity(&customCursor);

	// Game loop.
	while (Game::getInstance()->getWindow().isOpen())
	{
		while (Game::getInstance()->getWindow().pollEvent(gameEvents)) 
		{
			// Close game on Escape.
			if ((gameEvents.type == sf::Event::KeyPressed && gameEvents.key.code == sf::Keyboard::Escape) || (gameEvents.type == sf::Event::Closed))
			{
				Game::getInstance()->getWindow().close();
			}
		}

		// Draw background.
		Game::getInstance()->getWindow().draw(bgSprite);

		// Update/Draw each Entity.
		std::list<Entity*>::iterator entityIter = Game::getInstance()->getEntities().begin();
		for(entityIter; entityIter != Game::getInstance()->getEntities().end(); entityIter++)
		{
			(*entityIter)->update(gameTime);
			(*entityIter)->draw();
		}

		Game::getInstance()->getWindow().display();
		Game::getInstance()->getWindow().clear(sf::Color::White);

		gameTime = gameClock.restart().asSeconds();

		// Frame.
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

	} // End window is open

	Game::getInstance()->shutdown();

	return 0;
}