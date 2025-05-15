#include "Start.h"

bool Start::ChooseLanguage()
{
	setlocale(LC_ALL, "RU");

	string language;

	do {
		cout << "Choose language / Выберите язык (en - English, ru - Русский): ";
		cin >> language;

		system("cls");
	} while (language != "en" && language != "En" && language != "EN"
		&& language != "ru" && language != "Ru" && language != "RU");

	return language == "en" || language == "En" || language == "EN";
}

// http://forum.oszone.net/archive/index.php/t-44332.html
void Start::OpenWindowFullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

// https://www.cyberforum.ru/cpp-beginners/thread102665.html
void Start::HideCursor()
{
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &cursorInfo);
}