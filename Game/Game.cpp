#include "Game.h"

Game* Game::sInstance = NULL;

void Game::start()
{
	mWindow = new sf::RenderWindow(sf::VideoMode(1024, 768), "ShootEverything", 1);
	mWindow->setVerticalSyncEnabled(true);
	mWindow->setMouseCursorVisible(false);
}

void Game::addEntity(Entity *entity)
{
	mEntities.push_back(entity);
}

void Game::destroyEntity(Entity *entity)
{
	mEntities.remove(entity);
}

void Game::shutdown()
{
	std::list<Entity*>::iterator entityIter = mEntities.begin();
	for(entityIter; entityIter != mEntities.end(); entityIter)
	{
		entityIter = mEntities.erase(entityIter);
	}

	if(sInstance)
	{
		delete sInstance;
	}
}