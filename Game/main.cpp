#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Cursor.h"

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

	Cursor customCursor(
		new DrawableComponent(&gameWindow, "Assets/spaceCursor.png"), 
		new PositionComponent(),
		new MouseComponent());

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

		customCursor.update();
		customCursor.draw();

		gameWindow.display();
		gameWindow.clear(sf::Color::White);

		gameTime = gameClock.restart().asSeconds();
		sf::sleep(sf::milliseconds(10));

	} // End window is open

	return 0;
}