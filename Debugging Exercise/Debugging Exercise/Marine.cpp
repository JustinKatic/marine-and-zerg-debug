#include "Marine.h"



Marine::Marine()
{
	health = 50;
}


Marine::~Marine()
{

}

int Marine::attack()
{	
	return rand() % 8 + 1;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}

// Is there a Marine Alive?
bool Marine::marineAlive(vector<Marine> squad)
{
	return squad.size() > 0;
}
