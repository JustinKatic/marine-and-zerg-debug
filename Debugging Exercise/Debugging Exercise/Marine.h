#pragma once
#include "Entity.h"
#include <vector>
using namespace std;

class Marine : public Entity
{
public:
	Marine();
	~Marine();

	int attack();
	void takeDamage(int damage) override;
	bool marineAlive(vector<Marine> squad);

	vector<Marine> squad;
};

