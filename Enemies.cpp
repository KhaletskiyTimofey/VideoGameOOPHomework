#include "Enemies.h"

Enemies::~Enemies()
{
	delete[] enemies;
}

void Enemies::FindEnemiesOnMap(int enemiesCount, char** map, int mapWidth, int mapHeight)
{
	this->enemiesCount = enemiesCount;
	enemies = new Enemy[enemiesCount];
	int enemyId = 0;

	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (map[i][j] == '&')
			{
				enemies[enemyId].setX(j);
				enemies[enemyId].setY(i);

				if (++enemyId >= enemiesCount)
				{
					return;
				}
			}
		}
	}
}

int Enemies::GetEnemiesCount()
{
	return enemiesCount;
}

Enemy Enemies::GetEnemy(int index)
{
	return enemies[index];
}