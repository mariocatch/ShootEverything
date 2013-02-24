#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class BaseComponent
{
public:
	virtual void update(Entity& entity) = 0;
	
protected:
	BaseComponent() {}
	~BaseComponent() {}

private:
};

