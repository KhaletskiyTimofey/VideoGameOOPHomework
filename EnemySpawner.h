//#pragma once
//
//#include <iostream>
//
//#include "Enemy.h"
//
//using namespace std;
//
//class EnemySpawner
//{
//public:
//	Enemy* enemies;
//
//	EnemySpawner(int countOfEnemies)
//	{
//		enemies = new Enemy[countOfEnemies];
//
//		for (int i = 0; i < countOfEnemies; i++)
//		{
//			enemies[i].x = getRandomNumber(1, 9);
//			enemies[i].y = getRandomNumber(1, 8);
//		}
//	}
//
//	~EnemySpawner()
//	{
//		delete[] enemies;
//	}
//
//	int getRandomNumber(int start, int end)
//	{
//		return rand() % (end - start + 1) + start;
//	}
//};