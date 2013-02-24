#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include "Player.h"
#include "Cursor.h"
#include "Entity.h"

class Game
{
public:
	static Game* GetInstance()
	{
		if(!sInstance)
		{
			sInstance = new Game();
		}

		return sInstance;
	}

	~Game(void)
	{ 
		if(sInstance)
		{
			delete sInstance;
		}
	}

	void addEntity(Entity &entity);
	void destroyEntity(Entity &entity);
	std::list<Entity*> &getEntities() { return mEntities; }

private:
	static Game* sInstance;
	Game(void) { }
	std::list<Entity *> mEntities;
};

