#include "DrawableComponent.h"


DrawableComponent::DrawableComponent(sf::RenderWindow &window, std::string filePath)
{
	mWindow = &window;
	mTexture.loadFromFile(filePath);
	mSprite.setTexture(mTexture);
}

void DrawableComponent::update(sf::Vector2f &position)
{
	mSprite.setPosition(position);
}

void DrawableComponent::draw()
{
	mWindow->draw(mSprite);
}