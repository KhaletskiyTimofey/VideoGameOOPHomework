#pragma once

#include "main.h"

class Player
{
public:
	string name;
	int speed;
	int health;
	int damage;
	int armor;
	bool isAlive;

	string show_player_info()
	{
		string info = "";

		info += "Info about player: ";
		info += "Name: " + name;
		info += ", Speed: " + to_string(speed);
		info += ", Health: " + to_string(health);
		info += ", Damage: " + to_string(damage);
		info += ", Armor: " + to_string(armor);
		info += ", Alive: ";
		info += isAlive ? "Yes" : "No";

		return info;
	}
};