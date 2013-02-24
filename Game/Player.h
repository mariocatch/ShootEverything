#pragma once
#include "Entity.h"
#include "PositionComponent.h"
#include "DrawableComponent.h"
#include "PlayerInputComponent.h"
#include "MovableComponent.h"
#include "MouseComponent.h"
#include "GunComponent.h"

class Player : public Entity {
public:
	Player(
		DrawableComponent *drawableComponent, 
		PositionComponent *positionComponent, 
		PlayerInputComponent *playerInputComponent,
		MovableComponent *movableComponent,
		MouseComponent *mouseComponent,
		GunComponent *gunComponent) : 
			mDrawableComponent(drawableComponent), 
			mPositionComponent(positionComponent),
			mPlayerInputComponent(playerInputComponent),
			mMovableComponent(movableComponent),
			mMouseComponent(mouseComponent),
			mGunComponent(gunComponent)
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
	MouseComponent *mMouseComponent;
	GunComponent *mGunComponent;
};

