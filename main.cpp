//#include "Game.h"

#include <iostream>

#include "Start.h"
#include "Language.h"
#include "Game.h"

using namespace std;

int main()
{
	Start start;
	Language language(start.ChooseLanguage());

	start.OpenWindowFullscreen();
	start.HideCursor();

	Game game(1);

	return 0;
}