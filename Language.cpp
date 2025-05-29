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
		returnText = isEnglish ? "Coins" : "Монеты";
	}
	else if (text == "Game over")
	{
		returnText = isEnglish ? "GAME OVER!" : "ВЫ ПРОИГРАЛИ!";
	}
	else if (text == "Restarting")
	{
		returnText = isEnglish ? "Restarting..." : "Перезапуск...";
	}
	else if (text == "Win")
	{
		returnText = isEnglish ? "CONGRATULATIONS! YOU WIN!" : "ПОЗДРАВЛЯЮ! ВЫ ПОБЕДИЛИ!";
	}
	else if (text == "Level completed")
	{
		returnText = isEnglish ? "LEVEL COMPLETED!" : "УРОВЕНЬ ПРОЙДЕН!";
	}
	else if (text == "Loading")
	{
		returnText = isEnglish ? "Loading..." : "Загрузка...";
	}
	else if (text == "Start text 1")
	{
		returnText = isEnglish ? "Welcome to the game!" : "Добро пожаловать в игру!";
	}
	else if (text == "Start text 2")
	{
		returnText = isEnglish ? "Your goal here is to complete all 3 levels." 
			: "Здесь ваша цель — пройти все 3 уровня.";
	}
	else if (text == "Start text 3")
	{
		returnText = isEnglish ? "To do this, you must collect all the coins on the map."
			: "Для этого вы должны собрать все монеты на карте.";
	}
	else if (text == "Start text 4")
	{
		returnText = isEnglish ? "You can use the arrows or WASD to control it." 
			: "Для управления вы можете использовать стрелки или WASD.";
	}
	else if (text == "Wall")
	{
		returnText = isEnglish ? " it's a wall. You can't go through it." 
			: " — это стена. Вы не можете проходить сквозь неё.";
	}
	else if (text == "Player")
	{
		returnText = isEnglish ? " is a player. You control it." 
			: " — это игрок. Вы им управляете.";
	}
	else if (text == "Enemy")
	{
		returnText = isEnglish ? " is the enemy. If you touch it, you WILL LOSE!" 
			: " — это враг. Если вы коснётесь его, то вы ПРОИГРАЕТЕ!";
	}
	else if (text == "Coin")
	{
		returnText = isEnglish ? " it's a coin. You have to collect them all." 
			: " — это монета. Вы должны собрать их все.";
	}
	else if (text == "Start text end")
	{
		returnText = isEnglish ? "If you are ready, then press the space bar..." 
			: "Если вы готовы, то нажмите на пробел...";
	}

	return returnText;
}