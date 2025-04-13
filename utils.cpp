//#include "utils.h"
//
//// https://stackoverflow.com/questions/1670891/how-can-i-print-a-string-to-the-console-at-specific-coordinates-in-c
//void print(const string& text, int x, int y)
//{
//	printf("\033[%d;%dH%s\n", y + 1, x + 1, text.c_str());
//}
//
//void set_color(string color)
//{
//	if (color == "red")
//	{
//		cout << "\033[31m";
//	}
//	else if (color == "green")
//	{
//		cout << "\033[32m";
//	}
//	else if (color == "yellow")
//	{
//		cout << "\033[33m";
//	}
//	else if (color == "blue")
//	{
//		cout << "\033[34m";
//	}
//	else if (color == "purple")
//	{
//		cout << "\033[35m";
//	}
//	else if (color == "white")
//	{
//		cout << "\033[37m";
//	}
//}
//
//// https://www.techiedelight.com/ru/convert-char-to-string-cpp/
//string char_to_string(char symbol)
//{
//	string str(1, symbol);
//	return str;
//}