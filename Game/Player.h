#pragma once
#include "Entity.h"
#include "PositionComponent.h"
#include "DrawableComponent.h"
#include "PlayerInputComponent.h"
#include "MovableComponent.h"

class Player : public Entity {
public:
	Player(
		DrawableComponent *drawableComponent, 
		PositionComponent *positionComponent, 
		PlayerInputComponent *playerInputComponent,
		MovableComponent *movableComponent) : 
			mDrawableComponent(drawableComponent), 
			mPositionComponent(positionComponent),
			mPlayerInputComponent(playerInputComponent),
			mMovableComponent(movableComponent)
	{

	}

	~Player(void);

	void update(float t);
	void draw();

private:
	PositionComponent *mPositionComponent;
	DrawableComponent *mDrawableComponent;
	PlayerInputComponent *mPlayerInputComponent;
	MovableComponent *mMovableComponent;
};

