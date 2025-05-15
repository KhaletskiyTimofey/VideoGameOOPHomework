#include "FileReader.h"

void FileReader::readFile(string filePath)
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

		int lineNumber = 0;
		string line;

		getline(file, line);
		while (getline(file, line))
		{
			for (int i = 0; i < mapWidth; i++)
			{
				char a = line[i];
				map[lineNumber][i] = a;
			}
			if (++lineNumber >= mapHeight)
			{
				break;
			}
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

FileReader::~FileReader()
{
	for (int i = 0; i < mapHeight; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}

int FileReader::getMapWidth()
{
	return mapWidth;
}

int FileReader::getMapHeight()
{
	return mapHeight;
}

char** FileReader::getMap()
{
	return map;
}