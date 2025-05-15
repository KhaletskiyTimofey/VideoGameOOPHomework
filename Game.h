#pragma once

#include <Windows.h>
#include "Player.h"
#include "Enemy.h"
#include "FileReader.h"

class Game
{
private:
	int levelId;

	int mapWidth;
	int mapHeight;
	char** map;

	FileReader fileReader;
	Player player;
	int enemiesCount;
	Enemy* enemies;

	void print(const string& text, int x, int y);
	void setColor(string color);
	string charToString(char symbol);

	void findPlayerPosition();
	void playerMovement(int offsetX, int offsetY);

	int countEnemies();
	void findEnemyPositions();
	void moveEnemies();

	void checkKeys();

	void start();
	void update();

public:
	Game(int levelsCount);
	~Game();
};