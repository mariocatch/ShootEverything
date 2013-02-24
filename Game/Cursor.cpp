#include "Cursor.h"

Cursor::~Cursor(void) 
{
	if(mDrawableComponent)
	{
		delete mDrawableComponent;
	}

	if(mPositionComponent)
	{
		delete mPositionComponent;
	}

	if(mMouseComponent)
	{
		delete mMouseComponent;
	}
}

void Cursor::update(float t) {
	// Update the MouseComponent's position.
	mMouseComponent->update(mDrawableComponent->getWindow());

	// Update the Cursor's PositionComponent's position based off the MouseComponent's position.
	mPositionComponent->update(mMouseComponent->getPosition());

	// Update the Drawable objects of the Cursor (sprite/texture/etc).
	mDrawableComponent->update(mPositionComponent->getPosition());
}

void Cursor::draw() {
	// Draw everything about the Cursor.
	mDrawableComponent->draw();
}