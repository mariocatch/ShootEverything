#pragma once
#include <SFML/Window.hpp>

class PlayerInputComponent
{
public:
	PlayerInputComponent() { }
	~PlayerInputComponent(void) { }

	void update(sf::Vector2f &position, sf::Vector2f &velocity, float t);
	bool& getHasFired() { return mHasFired; }

private:
	bool mHasFired;
};

