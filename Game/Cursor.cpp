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
}

void Cursor::update(float t) {
	mMouseComponent->update(mDrawableComponent->getWindow());
	mPositionComponent->update(mMouseComponent->getPosition());
	mDrawableComponent->update(mPositionComponent->getPosition());
}

void Cursor::draw() {	
	mDrawableComponent->draw();
}