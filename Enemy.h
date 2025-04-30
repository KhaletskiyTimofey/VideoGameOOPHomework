#pragma once

#include <iostream>
#include <string>

using namespace std;

class Enemy
{
private:
	int x;
	int y;
	int health = 100;
	bool isAlive = true;

public:
	Enemy(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Enemy() : Enemy(0, 0) {}

	string toString()
	{
		string info = "";

		info += "X: " + to_string(x);
		info += ", Y: " + to_string(y);
		info += ", Health: " + to_string(health);
		info += ", Alive: ";
		info += isAlive ? "Yes" : "No";

		return info;
	}
};