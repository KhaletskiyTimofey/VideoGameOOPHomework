#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileReader
{
private:
	int mapWidth;
	int mapHeight;
	int coinsCount;
	char** map;

public:
	~FileReader();

	void readFile(string filePath);

	int getMapWidth();
	int getMapHeight();
	int getCoinsCount();
	char** getMap();
};