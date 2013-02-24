#include "PlayerInputComponent.h"

void PlayerInputComponent::update(sf::Vector2f &position, sf::Vector2f &velocity, float t)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		// Move left.
		position.x -= velocity.x * t;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		// Move right.
		position.x += velocity.x * t;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		// Fire.
		mHasFired = true;
	}
}