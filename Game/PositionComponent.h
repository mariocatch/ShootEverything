#pragma once
#include <SFML/Graphics.hpp>

class PositionComponent {
private:
	sf::Vector2f mPosition;

public:
	PositionComponent(sf::Vector2f position) : mPosition(position) { }
	~PositionComponent(void) { }

	void update(sf::Vector2f position) { mPosition = position; }
	sf::Vector2f &getPosition() { return mPosition; }
};