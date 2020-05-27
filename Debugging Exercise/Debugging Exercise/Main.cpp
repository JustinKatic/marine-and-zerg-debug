// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include "Marine.h"
#include "Zergling.h"
#include <time.h>

using namespace std;

Marine marine;
Zergling zergling;


int main()
{
	srand(time(nullptr));

	int squadSize = 10;
	int swarmSize = 20;

	// Set up the Squad and the Swarm at their initial sizes listed above

	for (size_t i = 0; i < squadSize; i++)
	{
		Marine m;
		marine.squad.push_back(m);
	}

	for (size_t i = 0; i < swarmSize; i++)
	{
		Zergling z;
		zergling.swarm.push_back(z);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;


	while (marine.marineAlive(marine.squad) && zergling.zerglingAlive(zergling.swarm)) // If anyone is left alive to fight . . .
	{
		
		{
			for (vector<Marine>::iterator i = marine.squad.begin(); i != marine.squad.end(); ++i) // loop through zerglings
			{
				if (!marine.marineAlive(marine.squad) || !zergling.zerglingAlive(zergling.swarm)) // if there's at least one zergling && atleast one marine alive
				{
					break;
				}
				cout << "A marine attacks for " << i->attack() << " damage." << endl;
				zergling.swarm.begin()->takeDamage(i->attack());
				if (zergling.swarm.begin()->isAlive())
				{
					cout << " zergling lives" << endl;
					cout << "zergling current health is " << zergling.swarm.begin() -> health << endl << endl;
				}
				else
				{
					zergling.swarm.erase(zergling.swarm.begin());
					cout << "The zergling succumbs to his wounds." << endl;
					cout << "the number of zergling left is :" << zergling.swarm.size() << endl << endl;
				}
			}
		}
		
		{
			for (vector<Zergling>::iterator i = zergling.swarm.begin(); i != zergling.swarm.end(); ++i) // loop through zerglings
			{
				if (!zergling.zerglingAlive(zergling.swarm) || !marine.marineAlive(marine.squad)) // if there's at least one zergling && atleast one marine alive
				{
					break;
				}
				cout << "A zergling attacks for " << i->attack() << " damage." << endl;
				marine.squad.begin()->takeDamage(i->attack());
				if (marine.squad.begin()->isAlive())
				{
					cout << " marine lives" << endl;
					cout << "marine current health is " << marine.squad.begin() ->health << endl << endl;
				}
				else
				{
					marine.squad.erase(marine.squad.begin());
					cout << "The marine succumbs to his wounds." << endl;
					cout << "the number of marines left is :" << marine.squad.size() << endl << endl;

				}
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marine.marineAlive(marine.squad))
	{
		cout << "The Marines win." << endl;
	}
	else
	{
		cout << "The Zerg win." << endl;
	}
}




