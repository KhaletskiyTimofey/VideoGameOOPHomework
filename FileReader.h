//#pragma once
//
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//class FileReader
//{
//public:
//	int mapWidth;
//	int mapHeight;
//	char** map;
//
//	FileReader(string filePath)
//	{
//		ifstream file;
//		file.open("Levels\\Level 1.txt");
//
//		if (file.is_open())
//		{
//			string t;
//			file >> t;
//			cout << t << endl;
//
//			string a;
//			file >> a;
//			cout << a << endl;
//		}
//	}
//
//	~FileReader()
//	{
//		
//	}
//};