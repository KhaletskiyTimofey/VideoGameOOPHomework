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
	coinsCount = fileReader.getCoinsCount();
	map = fileReader.getMap();

	enemyList.Clear();
	coins = 0;

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

	if (map[playerY][playerX] == '*')
	{
		map[playerY][playerX] = ' ';
		coins++;

		showCoins();
	}
}

void Game::moveEnemies()
{
	for (int i = 0; i < enemyList.GetSize(); i++)
	{
		int moveDirection = enemyList.GetEnemy(i).move(map, player.getX(), player.getY());

		if (moveDirection <= 4)
		{
			moveEnemy(i, moveDirection);
		}
		else
		{
			moveEnemy(i, moveDirection / 5 - 1);
			player.setIsAlive(false);
		}
	}
}

void Game::moveEnemy(int enemyId, int moveDirection)
{
	Enemy enemy = enemyList.GetEnemy(enemyId);
	int enemyX = enemy.getX();
	int enemyY = enemy.getY();
	int lastEnemyX = enemyX;
	int lastEnemyY = enemyY;

	enemy.setIsStayOnCoin(map[enemyY][enemyX] == '*');

	print(" ", enemyX * 2, enemyY);

	setColor("red");

	switch (moveDirection)
	{
	case 0: enemyY--; break;
	case 1: enemyX++; break;
	case 2: enemyY++; break;
	case 3: enemyX--; break;
	}

	enemy.setX(enemyX);
	enemy.setY(enemyY);
	enemy.setLastMoveDirection(moveDirection);

	enemyList.SetEnemy(enemyId, enemy);

	print("&", enemyX * 2, enemyY);

	if (enemy.getIsStayOnCoin())
	{
		setColor("purple");

		print("*", lastEnemyX * 2, lastEnemyY);
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

void Game::showCoins()
{
	for (int i = 7; i <= 10; i++)
	{
		print(" ", i, mapHeight + 1);
	}

	setColor("white");

	int textX = language.getIsEnglish() ? 7 : 8;

	if (coins <= 9)
	{
		print(to_string(coins), textX, mapHeight + 1);
	}
	else if (coins <= 99)
	{
		print(to_string(coins / 10), textX, mapHeight + 1);
		print(to_string(coins % 10), textX + 1, mapHeight + 1);
	}
	else
	{
		print(to_string(coins / 100), textX, mapHeight + 1);
		print(to_string(coins % 100 / 10), textX + 1, mapHeight + 1);
		print(to_string(coins % 10), textX + 2, mapHeight + 1);
	}
}

void Game::drawLevel()
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (map[i][j] == '#')
			{
				setColor("blue");
			}
			else if (map[i][j] == '*')
			{
				setColor("purple");
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

	setColor("white");

	cout << "\n" << language.GetText("Coins") << ": 0";
}

void Game::start()
{
	Start start;

	language.setIsEnglish(start.ChooseLanguage());

	start.OpenWindowFullscreen();
	start.HideCursor();

	cout << language.GetText("Start text 1") << endl;
	Sleep(1500);
	cout << language.GetText("Start text 2") << endl;
	Sleep(2000);
	cout << language.GetText("Start text 3") << endl;
	Sleep(2000);
	cout << language.GetText("Start text 4") << endl;
	Sleep(2000);

	setColor("blue");
	cout << "\n#";
	setColor("white");
	cout << language.GetText("Wall") << endl;
	
	setColor("yellow");
	cout << "@";
	setColor("white");
	cout << language.GetText("Player") << endl;
	
	setColor("red");
	cout << "&";
	setColor("white");
	cout << language.GetText("Enemy") << endl;
	
	setColor("purple");
	cout << "*";
	setColor("white");
	cout << language.GetText("Coin") << endl;

	Sleep(5000);

	cout << "\n" << language.GetText("Start text end") << endl;

	while (GetAsyncKeyState(VK_SPACE) == 0);

	system("cls");

	readLevel(1);
	drawLevel();
}

void Game::update(int tick)
{
	checkKeys();

	if (tick % 3 == 0)
	{
		moveEnemies();
	}

	if (!player.getIsAlive())
	{
		player.setIsAlive(true);
		
		Sleep(500);

		system("cls");
		setColor("red");

		cout << language.GetText("Game over") << endl;

		Sleep(1000);

		setColor("white");

		cout << language.GetText("Restarting") << endl;

		Sleep(500);

		system("cls");

		readLevel(currentLevel);
		drawLevel();
	}

	if (coins == coinsCount)
	{
		if (currentLevel == levelsCount)
		{
			Sleep(500);

			system("cls");
			setColor("green");

			cout << language.GetText("Win") << endl;

			Sleep(3000);

			isGameOpen = false;
		}
		else
		{
			currentLevel++;

			Sleep(500);

			system("cls");
			setColor("green");

			cout << language.GetText("Level completed") << endl;

			Sleep(1000);

			setColor("white");

			cout << language.GetText("Loading") << endl;

			Sleep(1000);

			system("cls");

			readLevel(currentLevel);
			drawLevel();
		}
	}
}

Game::Game(int levelsCount)
{
	isGameOpen = true;

	currentLevel = 1;
	this->levelsCount = levelsCount;

	int tick = 0;

	start();

	while (GetAsyncKeyState(VK_ESCAPE) == 0 && isGameOpen)
	{
		update(tick);

		tick++;

		Sleep(75);
	}

	system("cls");

	setColor("white");
}