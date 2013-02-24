#pragma once
#include <SFML/Graphics.hpp>
#include "DrawableComponent.h"

class MouseComponent {
private:
	sf::Vector2f mPosition;

public:
	MouseComponent () { }
	~MouseComponent (void) { }

	void update();
	sf::Vector2f &getPosition() { return mPosition; }
};