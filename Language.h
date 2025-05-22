#pragma once

#include <iostream>

using namespace std;

class Language
{
private:
	bool isEnglish;

public:
	Language();

	bool getIsEnglish();
	void setIsEnglish(bool isEnglish);

	string GetText(string text);
};