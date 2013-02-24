#pragma once
class Entity
{
public:
	virtual void update(float t) = 0;
	virtual void draw() = 0;
protected: 
	Entity(void);
	~Entity(void);
};

