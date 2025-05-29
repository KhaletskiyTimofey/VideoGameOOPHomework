#include "EnemyList.h"

EnemyList::~EnemyList()
{
	delete[] array;
}

void EnemyList::Add(Enemy enemy)
{
	if (array != nullptr)
	{
		Enemy* newArray = new Enemy[size + 1];

		for (int i = 0; i < size; i++)
		{
			newArray[i] = array[i];
		}
		newArray[size] = enemy;

		delete[] array;

		array = newArray;
		size++;
	}
	else
	{
		array = new Enemy[1];
		array[0] = enemy;
		size = 1;
	}
}

void EnemyList::Remove(int index)
{
	if (array != nullptr)
	{
		size--;
		Enemy* newArray = new Enemy[size];

		for (int i = 0; i < size; i++)
		{
			newArray[i] = array[i];
		}

		delete[] array;

		array = newArray;
	}
	else
	{
		array = nullptr;
		size = 0;
	}
}

Enemy EnemyList::GetEnemy(int index)
{
	if (index < 0 || index >= size || array == nullptr)
	{
		return Enemy();
	}

	return array[index];
}

void EnemyList::SetEnemy(int index, Enemy enemy)
{
	if (index < 0 || index >= size || array == nullptr)
	{
		return;
	}

	array[index] = enemy;
}

int EnemyList::GetSize()
{
	return size;
}

bool EnemyList::IsEmpty()
{
	return size == 0;
}

void EnemyList::Clear()
{
	if (array != nullptr)
	{
		array = nullptr;
		size = 0;
	}
}