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


