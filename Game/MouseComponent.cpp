#include "MouseComponent.h"

MouseComponent::~MouseComponent(void)
{
}

void MouseComponent::update(sf::RenderWindow &window) {
	mPosition = sf::Vector2f(sf::Mouse::getPosition(window));
}