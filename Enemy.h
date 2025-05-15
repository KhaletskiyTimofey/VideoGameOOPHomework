#pragma once

#include <iostream>
#include <string>

using namespace std;

class Enemy
{
private:
	int x;
	int y;

public:
	Enemy(int x, int y);
	Enemy() : Enemy(0, 0) {}

	bool move();

	int getX();
	void setX(int x);
	int getY();
	void setY(int y);

	string toString();
};