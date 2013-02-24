#include "MouseComponent.h"
#include "Game.h"

void MouseComponent::update() {
	mPosition = sf::Vector2f(sf::Mouse::getPosition(Game::getInstance()->getWindow()));
}