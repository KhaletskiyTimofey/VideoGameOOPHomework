#pragma once

#include <iostream>
#include <string>

using namespace std;

class Entity
{
protected:
	int x;
	int y;

public:
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);

	string toString();
};