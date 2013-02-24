#pragma once
#include <SFML/Graphics.hpp>
#include "BaseComponent.h"

class PositionComponent {
private:
	sf::Vector2f mPosition;

public:
	PositionComponent() { }
	~PositionComponent(void);

	void update(sf::Vector2f position) { mPosition = position; }
	sf::Vector2f getPosition() { return mPosition; }
};