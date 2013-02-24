#pragma once
#include "Entity.h"
#include "PositionComponent.h"
#include "DrawableComponent.h"
#include "MovableComponent.h"

class Bullet : public Entity {
public:
	Bullet(
		DrawableComponent *drawableComponent, 
		PositionComponent *positionComponent,
		MovableComponent *movableComponent) : 
			mDrawableComponent(drawableComponent), 
			mPositionComponent(positionComponent),
			mMovableComponent(movableComponent)
	{
		// Do nothing.
	}

	~Bullet(void);

	void update(float t);
	void draw();
	void setTrajectory(sf::Vector2f trajectory) { mTrajectory = trajectory; }

private:
	PositionComponent *mPositionComponent;
	DrawableComponent *mDrawableComponent;
	MovableComponent *mMovableComponent;
	sf::Vector2f mTrajectory;
};

