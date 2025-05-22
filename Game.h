#pragma once

#include <Windows.h>
#include "Start.h"
#include "Language.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyList.h"
#include "FileReader.h"

class Game
{
private:
	Language language;
	FileReader fileReader;
	Player player;
	EnemyList enemyList;

	int levelId;

	int mapWidth;
	int mapHeight;
	char** map;

	int coins;

	void print(const string& text, int x, int y);
	void setColor(string color);
	string charToString(char symbol);

	void readLevel(int levelId);

	void findPlayerPosition();
	void playerMovement(int offsetX, int offsetY);

	void findEnemies();
	int countEnemies();
	void moveEnemies();
	void moveEnemy(int enemyId, int moveDirection);

	void checkKeys();
	void showCoins();

	void start();
	void update(int tick);

public:
	Game();
};