#include "Entity.h"


Entity::Entity()
{
	health = 50;
	maxHealth = 100;
}

Entity::~Entity()
{
}

int Entity::attack()
{
	return 0;
}

void Entity::takeDamage(int damage)
{
	std::cout << "Base TakeDamage()" << std::endl;
}

bool Entity::isAlive()
{
	if (health <= 0)
	{
		return false;
	}
	 return true;
}



