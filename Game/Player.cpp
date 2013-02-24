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
	mPlayerInputComponent->update(mPositionComponent->getPosition(), mMovableComponent->getVelocity(), t);
	mDrawableComponent->update(mPositionComponent->getPosition());
}

void Player::draw() {	
	mDrawableComponent->draw();
}