#include "GunComponent.h"
#include "Game.h"

GunComponent::~GunComponent()
{
	// Delete bullets.
}

void GunComponent::update(bool& hasFired, sf::Vector2f sourcePosition, sf::Vector2f destinationPosition)
{
	// Create bullet.
	if(hasFired)
	{
		Bullet *bullet = new Bullet(
			new DrawableComponent("Assets/bullet.png"),
			new PositionComponent(sourcePosition),
			new MovableComponent(sf::Vector2f(150, 150)));

		Game::getInstance()->addEntity(bullet);

		hasFired = false;
	}
}