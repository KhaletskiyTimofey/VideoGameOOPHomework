#include "Language.h"

Language::Language()
{
	isEnglish = true;
}

bool Language::getIsEnglish()
{
	return isEnglish;
}

void Language::setIsEnglish(bool isEnglish)
{
	this->isEnglish = isEnglish;
}

string Language::GetText(string text)
{
	return "";
}