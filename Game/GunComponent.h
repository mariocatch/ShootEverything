#pragma once
#include <SFML\Graphics.hpp>
#include "Bullet.h"

class GunComponent
{
public:
	GunComponent(void) { }
	~GunComponent(void);

	void update(bool& hasFired, sf::Vector2f sourcePosition, sf::Vector2f destinationPosition);
};