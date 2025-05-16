#pragma once

#include <Windows.h>
#include "Start.h"
#include "Language.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemies.h"
#include "FileReader.h"

class Game
{
private:
	Language language;
	FileReader fileReader;
	Player player;
	Enemies enemies;

	int levelId;

	int mapWidth;
	int mapHeight;
	char** map;

	void print(const string& text, int x, int y);
	void setColor(string color);
	string charToString(char symbol);

	void readLevel(int levelId);

	void findPlayerPosition();
	void playerMovement(int offsetX, int offsetY);

	int countEnemies();
	void moveEnemies();

	void checkKeys();

	void start();
	void update();

public:
	Game();
};