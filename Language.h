#pragma once

#include <iostream>

using namespace std;

class Language
{
private:
	bool isEnglish;

public:
	Language();
	Language(bool isEnglish);
	string GetText(string text);
};