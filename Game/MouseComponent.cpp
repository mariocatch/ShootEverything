#include "MouseComponent.h"

void MouseComponent::update(sf::RenderWindow &window) {
	mPosition = sf::Vector2f(sf::Mouse::getPosition(window));
}