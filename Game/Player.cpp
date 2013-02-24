#include "Player.h"

Player::~Player(void) 
{
	if(mDrawableComponent)
	{
		delete mDrawableComponent;
	}

	if(mPositionComponent)
	{
		delete mPositionComponent;
	}

	if(mPlayerInputComponent)
	{
		delete mPlayerInputComponent;
	}

	if(mMovableComponent)
	{
		delete mMovableComponent;
	}
	
	if(mMouseComponent)
	{
		delete mMouseComponent;
	}

	if(mGunComponent)
	{
		delete mGunComponent;
	}
}

void Player::update(float t) {
	mMouseComponent->update();

	// Update the PlayerInputComponent (input handler) based off the Player's current position and velocity.
	mPlayerInputComponent->update(mPositionComponent->getPosition(), mMovableComponent->getVelocity(), t);

	mGunComponent->update(mPlayerInputComponent->getHasFired(), mPositionComponent->getPosition(), mMouseComponent->getPosition());

	// Update the Drawable objects of the Player (sprite/texture/etc).
	mDrawableComponent->update(mPositionComponent->getPosition());
}

void Player::draw() {
	// Draw everything about the Player.
	mDrawableComponent->draw();
}