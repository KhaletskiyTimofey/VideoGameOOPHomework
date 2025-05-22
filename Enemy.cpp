#include "Enemy.h"

Enemy::Enemy(int x, int y)
{
	this->x = x;
	this->y = y;
	lastMoveDirection = -100;
	isStayOnCoin = false;
}

int Enemy::getRandomNumber(int start, int end)
{
	return rand() % (end - start + 1) + start;
}

bool Enemy::isMoveToPlayer(char** map, int playerX, int playerY, int moveDirection)
{
	bool isWillTouchPlayer = false;

	switch (moveDirection)
	{
	case 0: if (playerX == x && playerY == y - 1) isWillTouchPlayer = true; break;
	case 1: if (playerX == x + 1 && playerY == y) isWillTouchPlayer = true; break;
	case 2: if (playerX == x && playerY == y + 1) isWillTouchPlayer = true; break;
	case 3: if (playerX == x - 1 && playerY == y) isWillTouchPlayer = true; break;
	}

	return isWillTouchPlayer;
}

bool Enemy::isCanMove(char** map, int moveDirection)
{
	bool isNoWall = false;

	switch (moveDirection)
	{
	case 0: if (map[y - 1][x] != '#') isNoWall = true; break;
	case 1: if (map[y][x + 1] != '#') isNoWall = true; break;
	case 2: if (map[y + 1][x] != '#') isNoWall = true; break;
	case 3: if (map[y][x - 1] != '#') isNoWall = true; break;
	}

	return isNoWall;
}

int Enemy::move(char** map, int playerX, int playerY)
{
	for (int i = 0; i < 4; i++)
	{
		if (isMoveToPlayer(map, playerX, playerY, i))
		{
			return i * 5 + 5;
		}
	}

	int moveDirectionsCount = 0;
	int* moveDirections = new int[10];

	for (int i = 0; i < 4; i++)
	{
		if ((getLastMoveDirection() + 2) % 4 != i && isCanMove(map, i))
		{
			if (i != getLastMoveDirection())
			{
				moveDirections[moveDirectionsCount] = i;
				moveDirectionsCount++;
			}
			else
			{
				for (int j = 0; j < 7; j++)
				{
					moveDirections[moveDirectionsCount] = i;
					moveDirectionsCount++;
				}
			}
		}
	}

	int moveDirection = -1;

	if (moveDirectionsCount > 0)
	{
		int moveDirectionId = getRandomNumber(0, moveDirectionsCount - 1);
		moveDirection = moveDirections[moveDirectionId];
	}

	delete[] moveDirections;

	return moveDirection;
}

int Enemy::getLastMoveDirection()
{
	return lastMoveDirection;
}

void Enemy::setLastMoveDirection(int lastMoveDirection)
{
	this->lastMoveDirection = lastMoveDirection;
}

bool Enemy::getIsStayOnCoin()
{
	return isStayOnCoin;
}

void Enemy::setIsStayOnCoin(bool isStayOnCoin)
{
	this->isStayOnCoin = isStayOnCoin;
}