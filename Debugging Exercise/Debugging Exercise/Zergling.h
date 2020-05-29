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

};

