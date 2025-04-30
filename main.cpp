//#include "Game.h"

#include <iostream>

#include "EnemySpawner.h"

#include "FileReader.h"

using namespace std;

int main()
{
	/*int count_of_enemies;

	cout << "Enter count of enemies: ";
	cin >> count_of_enemies;

	EnemySpawner enemy_spawner(count_of_enemies);

	Enemy* enemies = enemy_spawner.enemies;

	for (int i = 0; i < count_of_enemies; i++)
	{
		cout << enemies[i].toString() << endl;
	}*/

	FileReader file_reader("Levels\\Level 1.txt");

	return 0;
}