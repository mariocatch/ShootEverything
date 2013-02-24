#pragma once
#include <SFML/Graphics.hpp>
#include "PositionComponent.h"
#include "DrawableComponent.h"
#include "MouseComponent.h"


class Cursor {
public:
	Cursor(DrawableComponent *drawableComponent, PositionComponent *positionComponent, MouseComponent* mouseComponent) : 
		mDrawableComponent(drawableComponent), 
		mPositionComponent(positionComponent),
		mMouseComponent(mouseComponent)
	{
		mDrawableComponent->setOrigin(
		mDrawableComponent->getSprite().getGlobalBounds().width / 2, 
		mDrawableComponent->getSprite().getGlobalBounds().height / 2);
	}

	~Cursor(void);

	void update();
	void draw();

private:
	PositionComponent *mPositionComponent;
	DrawableComponent *mDrawableComponent;
	MouseComponent *mMouseComponent;
};

