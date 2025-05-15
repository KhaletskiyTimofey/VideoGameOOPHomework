#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
	int x;
	int y;
	bool isAlive = true;

public:
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	bool getIsAlive();
	void setIsAlive(bool isAlive);

	string toString();
};