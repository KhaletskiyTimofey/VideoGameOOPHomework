#include "Player.h"

int Player::getX()
{
	return x;
}

void Player::setX(int x)
{
	this->x = x;
}

int Player::getY()
{
	return y;
}

void Player::setY(int y)
{
	this->y = y;
}

bool Player::getIsAlive()
{
	return isAlive;
}

void Player::setIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

string Player::toString()
{
	string info = "";

	info += "X: " + to_string(x);
	info += ", Y: " + to_string(y);
	info += ", Alive: ";
	info += isAlive ? "Yes" : "No";

	return info;
}