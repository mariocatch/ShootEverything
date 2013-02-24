#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include "Player.h"
#include "Cursor.h"
#include "Entity.h"

class Game
{
public:
	static Game* getInstance()
	{
		if(!sInstance)
		{
			sInstance = new Game();
		}

		return sInstance;
	}

	~Game(void) 
	{
		if(mWindow)
		{
			delete mWindow;
		}
	}

	void start();
	void shutdown();
	void addEntity(Entity *entity);
	void destroyEntity(Entity *entity);
	std::list<Entity*> &getEntities() { return mEntities; }
	sf::RenderWindow& getWindow() { return *mWindow; }

private:
	static Game* sInstance;

	Game(void) { }
	std::list<Entity *> mEntities;
	sf::RenderWindow *mWindow;
};

