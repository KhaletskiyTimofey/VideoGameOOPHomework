#include "Player.h"

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

	info += Entity::toString();
	info += ", Alive: ";
	info += isAlive ? "Yes" : "No";

	return info;
}