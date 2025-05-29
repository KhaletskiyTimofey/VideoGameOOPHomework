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
	string returnText = "";

	if (text == "Coins")
	{
		returnText = isEnglish ? "Coins" : "������";
	}
	else if (text == "Game over")
	{
		returnText = isEnglish ? "GAME OVER!" : "�� ���������!";
	}
	else if (text == "Restarting")
	{
		returnText = isEnglish ? "Restarting..." : "����������...";
	}
	else if (text == "Win")
	{
		returnText = isEnglish ? "CONGRATULATIONS! YOU WIN!" : "����������! �� ��������!";
	}
	else if (text == "Level completed")
	{
		returnText = isEnglish ? "LEVEL COMPLETED!" : "������� �������!";
	}
	else if (text == "Loading")
	{
		returnText = isEnglish ? "Loading..." : "��������...";
	}
	else if (text == "Start text 1")
	{
		returnText = isEnglish ? "Welcome to the game!" : "����� ���������� � ����!";
	}
	else if (text == "Start text 2")
	{
		returnText = isEnglish ? "Your goal here is to complete all 3 levels." 
			: "����� ���� ���� � ������ ��� 3 ������.";
	}
	else if (text == "Start text 3")
	{
		returnText = isEnglish ? "To do this, you must collect all the coins on the map."
			: "��� ����� �� ������ ������� ��� ������ �� �����.";
	}
	else if (text == "Start text 4")
	{
		returnText = isEnglish ? "You can use the arrows or WASD to control it." 
			: "��� ���������� �� ������ ������������ ������� ��� WASD.";
	}
	else if (text == "Wall")
	{
		returnText = isEnglish ? " it's a wall. You can't go through it." 
			: " � ��� �����. �� �� ������ ��������� ������ ��.";
	}
	else if (text == "Player")
	{
		returnText = isEnglish ? " is a player. You control it." 
			: " � ��� �����. �� �� ����������.";
	}
	else if (text == "Enemy")
	{
		returnText = isEnglish ? " is the enemy. If you touch it, you WILL LOSE!" 
			: " � ��� ����. ���� �� �������� ���, �� �� ����������!";
	}
	else if (text == "Coin")
	{
		returnText = isEnglish ? " it's a coin. You have to collect them all." 
			: " � ��� ������. �� ������ ������� �� ���.";
	}
	else if (text == "Start text end")
	{
		returnText = isEnglish ? "If you are ready, then press the space bar..." 
			: "���� �� ������, �� ������� �� ������...";
	}

	return returnText;
}