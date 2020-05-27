#pragma once
#include <iostream>

class Entity
{
public:
	Entity();
	~Entity();

	virtual int attack();
	virtual void takeDamage(int damage);
	bool isAlive();

	int health;
	int maxHealth;
};

