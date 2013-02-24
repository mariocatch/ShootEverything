#pragma once
#include <SFML\Graphics.hpp>

class MovableComponent
{
private:
	sf::Vector2f mVelocity;

public:
	MovableComponent(sf::Vector2f velocity) : mVelocity(velocity) { }
	~MovableComponent(void) { }
	sf::Vector2f &getVelocity() { return mVelocity; }
	void setVelocity(sf::Vector2f velocity) { mVelocity = velocity; }
};

