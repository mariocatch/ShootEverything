#include "Bullet.h"

Bullet::~Bullet(void) 
{
	if(mDrawableComponent)
	{
		delete mDrawableComponent;
	}

	if(mPositionComponent)
	{
		delete mPositionComponent;
	}

	if(mMovableComponent)
	{
		delete mMovableComponent;
	}
}

void Bullet::update(float t) {
	// Update the Drawable objects of the Bullet (sprite/texture/etc).
	mDrawableComponent->update(mPositionComponent->getPosition());
}

void Bullet::draw() {
	// Draw everything about the Player.
	mDrawableComponent->draw();
}