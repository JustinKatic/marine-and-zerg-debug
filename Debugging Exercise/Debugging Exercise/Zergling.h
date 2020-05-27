#pragma once
#include "Entity.h"
#include <vector>
using namespace std;

class Zergling : public Entity
{
public:
	Zergling();
	~Zergling();

	int attack();
	void takeDamage(int damage);
	vector<Zergling> swarm;
	bool zerglingAlive(vector<Zergling> swarm);
};

