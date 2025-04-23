//#pragma once
//
//#include <Windows.h>
//#include "Player.h"
//#include "Enemy.h"
//#include "FileReader.h"
//
//class Game
//{
//public:
//	Game(int levelsCount)
//	{
//		
//	}
//
//	// https://stackoverflow.com/questions/1670891/how-can-i-print-a-string-to-the-console-at-specific-coordinates-in-c
//	void print(const string& text, int x, int y)
//	{
//		printf("\033[%d;%dH%s\n", y + 1, x + 1, text.c_str());
//	}
//
//	// https://habr.com/ru/companies/macloud/articles/558316/
//	void set_color(string color)
//	{
//		if (color == "red")
//		{
//			cout << "\033[31m";
//		}
//		else if (color == "green")
//		{
//			cout << "\033[32m";
//		}
//		else if (color == "yellow")
//		{
//			cout << "\033[33m";
//		}
//		else if (color == "blue")
//		{
//			cout << "\033[34m";
//		}
//		else if (color == "purple")
//		{
//			cout << "\033[35m";
//		}
//		else if (color == "white")
//		{
//			cout << "\033[37m";
//		}
//	}
//
//	// https://www.techiedelight.com/ru/convert-char-to-string-cpp/
//	string char_to_string(char symbol)
//	{
//		string str(1, symbol);
//		return str;
//	}
//};
//
////void find_player_position(char** map, int width, int height, int& player_x, int& player_y)
////{
////	for (int i = 0; i < height; i++)
////	{
////		for (int j = 0; j < width; j++)
////		{
////			if (map[i][j] == '@')
////			{
////				player_x = j;
////				player_y = i;
////				break;
////			}
////		}
////	}
////}
////
////void move_player(char** map, int width, int height, int& player_x, int& player_y, int offset_x, int offset_y)
////{
////	if (offset_x == 0 && offset_y == 0 
////		|| player_x + offset_x < 0 || player_y + offset_y < 0 
////		|| player_x + offset_x >= width || player_y + offset_y >= height)
////	{
////		return;
////	}
////
////	print(" ", player_x * 2, player_y);
////
////	if (offset_x != 0 && map[player_y][player_x + offset_x] != '#')
////	{
////		player_x += offset_x;
////	}
////	if (offset_y != 0 && map[player_y + offset_y][player_x] != '#')
////	{
////		player_y += offset_y;
////	}
////
////	set_color("yellow");
////
////	print("@", player_x * 2, player_y);
////}
////
////int main()
////{
////	int player_speed = 1;
////	int player_x, player_y;
////	find_player_position(map, width, height, player_x, player_y);
////
////	for (int i = 0; i < height; i++)
////	{
////		for (int j = 0; j < width; j++)
////		{
////			if (map[i][j] != '@')
////			{
////				set_color("blue");
////			}
////			else
////			{
////				set_color("yellow");
////			}
////
////			print(char_to_string(map[i][j]), j * 2, i);
////		}
////	}
////
////	while (GetAsyncKeyState(VK_ESCAPE) == 0)
////	{
////		int player_offset_x = 0;
////		int	player_offset_y = 0;
////
////		if (GetAsyncKeyState(VK_UP) != 0 || GetAsyncKeyState(0x57/*W*/) != 0)
////		{
////			player_offset_y = -player_speed;
////		}
////		else if (GetAsyncKeyState(VK_DOWN) != 0 || GetAsyncKeyState(0x53/*S*/) != 0)
////		{
////			player_offset_y = player_speed;
////		}
////		if (GetAsyncKeyState(VK_LEFT) != 0 || GetAsyncKeyState(0x41/*A*/) != 0)
////		{
////			player_offset_x = -player_speed;
////		}
////		else if (GetAsyncKeyState(VK_RIGHT) != 0 || GetAsyncKeyState(0x44/*D*/) != 0)
////		{
////			player_offset_x = player_speed;
////		}
////
////		move_player(map, width, height, player_x, player_y, player_offset_x, player_offset_y);
////
////		Sleep(100);
////	}
////
////	set_color("white");
////
////	return 0;
////}