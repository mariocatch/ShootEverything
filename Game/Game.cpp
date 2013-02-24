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