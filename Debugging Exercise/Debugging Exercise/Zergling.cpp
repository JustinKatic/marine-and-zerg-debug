#include "Zergling.h"
#include <random>
#include <time.h>

Zergling::Zergling()
{
	health = 30;
}


Zergling::~Zergling()
{

}

int Zergling::attack()
{	
	
	return rand() % 3 + 1;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}


// Is there a zergling Alive
bool Zergling::zerglingAlive(vector<Zergling> swarm)
{
	return swarm.size() > 0;
}
