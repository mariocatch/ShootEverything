#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Cursor.h"
#include "Player.h"
#include "Game.h"

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(1024, 768), "ShootEverything", 1);
	gameWindow.setVerticalSyncEnabled(true);
	gameWindow.setMouseCursorVisible(false);

	sf::Clock gameClock;
	sf::Event gameEvents;
	float gameTime = 0;

	sf::Texture bgTexture;
	bgTexture.loadFromFile("Assets/spaceBackground.png");
	sf::Sprite bgSprite;
	bgSprite.setTexture(bgTexture);

	Player player(
		new DrawableComponent(gameWindow, "Assets/spaceman.png"), 
		new PositionComponent(sf::Vector2f(10, 700)),
		new PlayerInputComponent(),
		new MovableComponent(sf::Vector2f(150, 150)));
	Game::GetInstance()->addEntity(player);

	Cursor customCursor(
		new DrawableComponent(gameWindow, "Assets/spaceCursor.png"), 
		new PositionComponent(sf::Vector2f(0, 0)),
		new MouseComponent());
	Game::GetInstance()->addEntity(customCursor);

	while (gameWindow.isOpen())
	{
		while (gameWindow.pollEvent(gameEvents)) 
		{
			if ((gameEvents.type == sf::Event::KeyPressed && gameEvents.key.code == sf::Keyboard::Escape) || (gameEvents.type == sf::Event::Closed))
			{
				gameWindow.close();
			}
		}

		gameWindow.draw(bgSprite);

		std::list<Entity*>::iterator entityIter = Game::GetInstance()->getEntities().begin();
		for(entityIter; entityIter != Game::GetInstance()->getEntities().end(); entityIter++)
		{
			(*entityIter)->update(gameTime);
			(*entityIter)->draw();
		}

		gameWindow.display();
		gameWindow.clear(sf::Color::White);

		gameTime = gameClock.restart().asSeconds();
		sf::sleep(sf::milliseconds(10));

	} // End window is open

	Game::GetInstance()->destroyEntity(player);
	Game::GetInstance()->destroyEntity(customCursor);

	return 0;
}