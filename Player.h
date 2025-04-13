#pragma once

#include "main.h"

class Player
{
public:
	string name;
	int speed;
	int health;
	int damage;
	int armor;
	bool isAlive;

	Player()
	{
		name = "No Name";
		speed = 1;
		health = 100;
		damage = 10;
		armor = 0;
		isAlive = true;
	}

	Player(string inputName, int inputSpeed, int inputHealth, int inputDamage, int inputArmor, bool inputIsAlive)
	{
		name = inputName;
		speed = inputSpeed;
		health = inputHealth;
		damage = inputDamage;
		armor = inputArmor;
		isAlive = inputIsAlive;
	}

	~Player()
	{

	}

	string toString()
	{
		string info = "";

		info += "Info about player:\n";
		info += name + ": ";
		info += "Speed: " + to_string(speed);
		info += ", Health: " + to_string(health);
		info += ", Damage: " + to_string(damage);
		info += ", Armor: " + to_string(armor);
		info += ", Alive: ";
		info += isAlive ? "Yes" : "No";

		return info;
	}

	string getName()
	{
		return name;
	}

	int getSpeed()
	{
		return speed;
	}

	int getHealth()
	{
		return health;
	}

	int getDamage()
	{
		return damage;
	}

	int getArmor()
	{
		return armor;
	}

	bool getIsAlive()
	{
		return isAlive;
	}
};