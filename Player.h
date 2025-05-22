#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	bool isAlive = true;

public:
	bool getIsAlive();
	void setIsAlive(bool isAlive);

	string toString();
};