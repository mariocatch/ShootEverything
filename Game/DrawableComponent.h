#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class DrawableComponent
{
public:
	DrawableComponent(std::string filePath);
	~DrawableComponent(void) { }

	sf::Sprite getSprite() { return mSprite; }
	void setSprite(sf::Sprite sprite) { mSprite = sprite; }
	void setOrigin(sf::Vector2f originCoordinates) { mOriginCoordinates = originCoordinates; }
	void setOrigin(float x, float y) { mOriginCoordinates = sf::Vector2f(x, y); }
	void update(sf::Vector2f &position);
	void draw();
private:
	sf::Sprite mSprite;
	sf::Texture mTexture;
	sf::Vector2f mOriginCoordinates;
};