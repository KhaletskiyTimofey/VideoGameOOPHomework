#include "Game.h"

// https://stackoverflow.com/questions/1670891/how-can-i-print-a-string-to-the-console-at-specific-coordinates-in-c
void Game::print(const string& text, int x, int y)
{
	printf("\033[%d;%dH%s\n", y + 1, x + 1, text.c_str());
}

// https://habr.com/ru/companies/macloud/articles/558316/
void Game::setColor(string color)
{
	if (color == "red")
	{
		cout << "\033[31m";
	}
	else if (color == "green")
	{
		cout << "\033[32m";
	}
	else if (color == "yellow")
	{
		cout << "\033[33m";
	}
	else if (color == "blue")
	{
		cout << "\033[34m";
	}
	else if (color == "purple")
	{
		cout << "\033[35m";
	}
	else if (color == "white")
	{
		cout << "\033[37m";
	}
}

// https://www.techiedelight.com/ru/convert-char-to-string-cpp/
string Game::charToString(char symbol)
{
	string str(1, symbol);
	return str;
}

void Game::readLevel(int levelId)
{
	fileReader.readFile("Levels\\Level " + to_string(levelId) + ".txt");
	mapWidth = fileReader.getMapWidth();
	mapHeight = fileReader.getMapHeight();
	map = fileReader.getMap();

	findPlayerPosition();
	findEnemies();
}

void Game::findPlayerPosition()
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (map[i][j] == '@')
			{
				player.setX(j);
				player.setY(i);

				return;
			}
		}
	}
}

void Game::findEnemies()
{
	int enemiesCount = countEnemies();
	int enemyId = 0;

	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (map[i][j] == '&')
			{
				enemyList.Add(Enemy(j, i));

				if (++enemyId >= enemiesCount)
				{
					return;
				}
			}
		}
	}
}

int Game::countEnemies()
{
	int enemiesCount = 0;

	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (map[i][j] == '&')
			{
				enemiesCount++;
			}
		}
	}

	return enemiesCount;
}

void Game::playerMovement(int offsetX, int offsetY)
{
	int playerX = player.getX();
	int playerY = player.getY();

	if (offsetX == 0 && offsetY == 0
		|| player.getX() + offsetX < 0 || player.getY() + offsetY < 0
		|| player.getX() + offsetX >= mapWidth || player.getY() + offsetY >= mapHeight
		|| offsetY == 0 && map[playerY][playerX + offsetX] == '#'
		|| offsetX == 0 && map[playerY + offsetY][playerX] == '#'
		|| offsetX != 0 && offsetY != 0
		&& map[playerY][playerX + offsetX] == '#' && map[playerY + offsetY][playerX] == '#')
	{
		return;
	}

	print(" ", playerX * 2, playerY);

	if (map[playerY][playerX + offsetX] != '#')
	{
		player.setX(playerX + offsetX);
		playerX = player.getX();
	}
	if (map[playerY + offsetY][playerX] != '#')
	{
		player.setY(playerY + offsetY);
		playerY = player.getY();
	}

	setColor("yellow");

	print("@", playerX * 2, playerY);
}

void Game::moveEnemies()
{
	for (int i = 0; i < enemyList.GetSize(); i++)
	{
		if (enemyList.GetEnemy(i).move())
		{
			player.setIsAlive(false);
		}
	}
}

void Game::checkKeys()
{
	int playerOffsetX = 0;
	int playerOffsetY = 0;

	if (GetAsyncKeyState(VK_UP) != 0 || GetAsyncKeyState(0x57/*W*/) != 0)
	{
		playerOffsetY = -1;
	}
	else if (GetAsyncKeyState(VK_DOWN) != 0 || GetAsyncKeyState(0x53/*S*/) != 0)
	{
		playerOffsetY = 1;
	}
	if (GetAsyncKeyState(VK_LEFT) != 0 || GetAsyncKeyState(0x41/*A*/) != 0)
	{
		playerOffsetX = -1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) != 0 || GetAsyncKeyState(0x44/*D*/) != 0)
	{
		playerOffsetX = 1;
	}

	playerMovement(playerOffsetX, playerOffsetY);
}

void Game::start()
{
	Start start;
	Language language(start.ChooseLanguage());

	start.OpenWindowFullscreen();
	start.HideCursor();

	readLevel(1);

	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (map[i][j] == '#')
			{
				setColor("blue");
			}
			else if (map[i][j] == '&')
			{
				setColor("red");
			}
			else
			{
				setColor("yellow");
			}

			print(charToString(map[i][j]), j * 2, i);
		}
	}
}

void Game::update()
{
	checkKeys();
	moveEnemies();
}

Game::Game()
{
	start();

	while (GetAsyncKeyState(VK_ESCAPE) == 0)
	{
		update();

		Sleep(75);
	}

	setColor("white");
}