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
	char** map;

public:
	FileReader(string filePath)
	{
		ifstream file;
		file.open(filePath);

		if (file.is_open())
		{
			file >> mapWidth >> mapHeight;

			map = new char* [mapHeight];
			for (int i = 0; i < mapHeight; i++)
			{
				map[i] = new char[mapWidth];
			}

			int lineNumber = 1;
			string line;

			while (getline(file, line))
			{
				for (int i = 0; i < mapWidth; i++)
				{
					map[lineNumber][i] = line[i];
				}

				lineNumber++;
			}
		}
		else
		{
			mapWidth = 0;
			mapHeight = 0;
			map = nullptr;
		}

		file.close();
	}

	~FileReader()
	{
		
	}
};