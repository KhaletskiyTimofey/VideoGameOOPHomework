#include "Player.h"

void change_player_info(Player& player, string name, int speed, int health, int damage, int armor, bool isAlive)
{
	player.name = name;
	player.speed = speed;
	player.health = health;
	player.damage = damage;
	player.armor = armor;
	player.isAlive = isAlive;
}

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

	cout << "Before:" << endl;
	cout << player.show_player_info() << endl;

	change_player_info(player, "Timofey", 3, 100, 10, 50, true);

	cout << "After:" << endl;
	cout << player.show_player_info() << endl;

	return 0;
}