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


