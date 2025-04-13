//#include <Windows.h>
//#include "utils.h"
#include "Player.h"

int main()
{
	string name;
	cout << "Enter name of the player: ";
	cin >> name;

	int speed;
	cout << "Enter speed of the player: ";
	cin >> speed;

	int health;
	cout << "Enter health of the player: ";
	cin >> health;

	int damage;
	cout << "Enter damage of the player: ";
	cin >> damage;

	int armor;
	cout << "Enter armor of the player: ";
	cin >> armor;

	bool isAlive;
	char answer;
	cout << "Enter is player alive (y/n): ";
	cin >> answer;
	isAlive = tolower(answer) == 'y';

	Player player{ name, speed, health, damage, armor, isAlive };

	cout << player.toString() << endl;

	return 0;
}

//void find_player_position(char** map, int width, int height, int& player_x, int& player_y)
//{
//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//		{
//			if (map[i][j] == '@')
//			{
//				player_x = j;
//				player_y = i;
//				break;
//			}
//		}
//	}
//}
//
//void move_player(char** map, int width, int height, int& player_x, int& player_y, int offset_x, int offset_y)
//{
//	if (offset_x == 0 && offset_y == 0 
//		|| player_x + offset_x < 0 || player_y + offset_y < 0 
//		|| player_x + offset_x >= width || player_y + offset_y >= height)
//	{
//		return;
//	}
//
//	print(" ", player_x * 2, player_y);
//
//	if (offset_x != 0 && map[player_y][player_x + offset_x] != '#')
//	{
//		player_x += offset_x;
//	}
//	if (offset_y != 0 && map[player_y + offset_y][player_x] != '#')
//	{
//		player_y += offset_y;
//	}
//
//	set_color("yellow");
//
//	print("@", player_x * 2, player_y);
//}
//
//int main()
//{
//	const int width = 11;
//	const int height = 10;
//
//	char map_static[height][width]{
//		{'#','#','#','#','#','#','#','#','#','#','#'},
//		{'#',' ','#',' ',' ',' ','#',' ',' ',' ','#'},
//		{'#',' ','#',' ','#',' ','#',' ','#',' ','#'},
//		{'#',' ','#',' ','#',' ','#',' ','#',' ','#'},
//		{'#',' ','#','#','#',' ','#','#','#',' ','#'},
//		{'#',' ','#',' ','#',' ','#',' ','#',' ','#'},
//		{'#',' ',' ',' ','#',' ',' ',' ','#',' ','#'},
//		{'#',' ','#','#','#',' ','#','#','#',' ','#'},
//		{'#',' ',' ',' ',' ','@',' ',' ',' ',' ','#'},
//		{'#','#','#','#','#','#','#','#','#','#','#'}
//	};
//
//	char** map = new char* [height];
//
//	for (int i = 0; i < height; i++)
//	{
//		map[i] = new char[width];
//
//		for (int j = 0; j < width; j++)
//		{
//			map[i][j] = map_static[i][j];
//		}
//	}
//
//	int player_speed = 1;
//	int player_x, player_y;
//	find_player_position(map, width, height, player_x, player_y);
//
//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//		{
//			if (map[i][j] != '@')
//			{
//				set_color("blue");
//			}
//			else
//			{
//				set_color("yellow");
//			}
//
//			print(char_to_string(map[i][j]), j * 2, i);
//		}
//	}
//
//	while (GetAsyncKeyState(VK_ESCAPE) == 0)
//	{
//		int player_offset_x = 0;
//		int	player_offset_y = 0;
//
//		if (GetAsyncKeyState(VK_UP) != 0 || GetAsyncKeyState(0x57/*W*/) != 0)
//		{
//			player_offset_y = -player_speed;
//		}
//		else if (GetAsyncKeyState(VK_DOWN) != 0 || GetAsyncKeyState(0x53/*S*/) != 0)
//		{
//			player_offset_y = player_speed;
//		}
//		if (GetAsyncKeyState(VK_LEFT) != 0 || GetAsyncKeyState(0x41/*A*/) != 0)
//		{
//			player_offset_x = -player_speed;
//		}
//		else if (GetAsyncKeyState(VK_RIGHT) != 0 || GetAsyncKeyState(0x44/*D*/) != 0)
//		{
//			player_offset_x = player_speed;
//		}
//
//		move_player(map, width, height, player_x, player_y, player_offset_x, player_offset_y);
//
//		Sleep(100);
//	}
//
//	set_color("white");
//
//	return 0;
//}