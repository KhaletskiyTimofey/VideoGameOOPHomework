#include "Player.h"

int main()
{
	Player player;

	cout << "Enter name of the player: ";
	cin >> player.name;

	cout << "Enter speed of the player: ";
	cin >> player.speed;

	cout << "Enter health of the player: ";
	cin >> player.health;

	cout << "Enter damage of the player: ";
	cin >> player.damage;

	cout << "Enter armor of the player: ";
	cin >> player.armor;

	cout << "Enter is player alive (y/n): ";
	char answer;
	cin >> answer;
	player.isAlive = tolower(answer) == 'y';

	cout << "\nInfo about player: " << endl;
	cout << "\tName: " << player.name << endl;
	cout << "\tSpeed: " << player.speed << endl;
	cout << "\tHealth: " << player.health << endl;
	cout << "\tDamage: " << player.damage << endl;
	cout << "\tArmor: " << player.armor << endl;
	cout << "\tAlive: " << (player.isAlive ? "Yes" : "No") << endl;

	return 0;
}