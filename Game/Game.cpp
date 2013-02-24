#include "Game.h"

Game* Game::sInstance = NULL;

void Game::addEntity(Entity &entity)
{
	mEntities.push_back(&entity);
}

void Game::destroyEntity(Entity &entity)
{
	mEntities.remove(&entity);
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