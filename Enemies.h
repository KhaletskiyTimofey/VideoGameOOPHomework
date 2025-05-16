#pragma once

#include "Enemy.h"

class Enemies
{
private:
	int enemiesCount;
	Enemy* enemies;

public:
	~Enemies();

	void FindEnemiesOnMap(int enemiesCount, char** map, int mapWidth, int mapHeight);

	int GetEnemiesCount();
	Enemy GetEnemy(int index);
};