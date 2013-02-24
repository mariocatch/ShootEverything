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
}

void Player::update(float t) {
	// Update the PlayerInputComponent (input handler) based off the Player's current position and velocity.
	mPlayerInputComponent->update(mPositionComponent->getPosition(), mMovableComponent->getVelocity(), t);

	// Update the Drawable objects of the Player (sprite/texture/etc).
	mDrawableComponent->update(mPositionComponent->getPosition());
}

void Player::draw() {
	// Draw everything about the Player.
	mDrawableComponent->draw();
}