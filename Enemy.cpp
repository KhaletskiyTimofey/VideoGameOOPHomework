#include "Enemy.h"

Enemy::Enemy(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Enemy::move()
{
	return false;
}

int Enemy::getX()
{
	return x;
}

void Enemy::setX(int x)
{
	this->x = x;
}

int Enemy::getY()
{
	return y;
}

void Enemy::setY(int y)
{
	this->y = y;
}

string Enemy::toString()
{
	string info = "";

	info += "X: " + to_string(x);
	info += ", Y: " + to_string(y);

	return info;
}