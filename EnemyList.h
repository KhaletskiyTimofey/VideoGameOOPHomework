#pragma once

#include <iostream>
#include "Enemy.h"

using namespace std;

class EnemyList
{
private:
	Enemy* array;
	int size;

public:
	~EnemyList();

	void Add(Enemy enemy);
	void Remove(int index);

	Enemy GetEnemy(int index);

	int GetSize();
	bool IsEmpty();
};