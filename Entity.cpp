#include "Entity.h"

int Entity::getX()
{
	return x;
}

void Entity::setX(int x)
{
	this->x = x;
}

int Entity::getY()
{
	return y;
}

void Entity::setY(int y)
{
	this->y = y;
}

string Entity::toString()
{
	string info = "";

	info += "X: " + to_string(x);
	info += ", Y: " + to_string(y);

	return info;
}