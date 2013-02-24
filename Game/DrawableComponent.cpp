#include "DrawableComponent.h"
#include "Game.h"

DrawableComponent::DrawableComponent(std::string filePath)
{
	mTexture.loadFromFile(filePath);
	mSprite.setTexture(mTexture);
}

void DrawableComponent::update(sf::Vector2f &position)
{
	mSprite.setPosition(position);
}

void DrawableComponent::draw()
{
	Game::getInstance()->getWindow().draw(mSprite);
}