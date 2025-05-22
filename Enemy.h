#pragma once

#include "Entity.h"

class Enemy : public Entity
{
private:
	int lastMoveDirection;
	bool isStayOnCoin;

	int getRandomNumber(int start, int end);
	bool isMoveToPlayer(char** map, int playerX, int playerY, int moveDirection);
	bool isCanMove(char** map, int moveDirection);

public:
	Enemy(int x, int y);
	Enemy() : Enemy(0, 0) {}

	int move(char** map, int playerX, int playerY);

	int getLastMoveDirection();
	void setLastMoveDirection(int lastMoveDirection);
	bool getIsStayOnCoin();
	void setIsStayOnCoin(bool isStayOnCoin);
};