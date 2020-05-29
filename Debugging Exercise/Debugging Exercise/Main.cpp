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


bool IsGroupAlive(vector<Entity> group)
{
	return group.size() > 0;
}

int main()
{
	//random time seed
	srand(time(nullptr));
	vector<Entity> squad;
	vector<Entity> swarm;

	// Set up the Squad and the Swarm at their initial sizes listed above
	int squadSize = 10;
	int swarmSize = 20;

	//populates the vector 
	for (size_t i = 0; i < squadSize; i++)
	{
		Marine m;
		squad.push_back(m);
	}

	for (size_t i = 0; i < swarmSize; i++)
	{
		Zergling z;
		swarm.push_back(z);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;


	while (IsGroupAlive(squad) && IsGroupAlive(swarm)) // If anyone is left alive to fight . . .
	{

		for (vector<Entity>::iterator i = squad.begin(); i != squad.end(); ++i) // loop through zerglings
		{
			if (!IsGroupAlive(squad) || !IsGroupAlive(swarm)) // if there's at least one zergling && atleast one marine alive
			{
				break;
			}
			cout << "A marine attacks for " << marine.attack() << " damage." << endl;
			//swawm in first pos of vector takes dmg from marine
			swarm.begin()->takeDamage(marine.attack());

			//if zergling didnt die 
			if (swarm.begin()->isAlive())
			{
				cout << " zergling lives" << endl;
				cout << "zergling current health is " << swarm.begin()->health << endl << endl;
			}
			//if zergling died
			else
			{
				swarm.erase(swarm.begin());
				cout << "The zergling succumbs to his wounds." << endl;
				cout << "the number of zergling left is :" << swarm.size() << endl << endl;
			}
		}



		for (vector<Entity>::iterator i = swarm.begin(); i != swarm.end(); ++i) // loop through zerglings
		{
			if (!IsGroupAlive(swarm) || !IsGroupAlive(squad))// if there's at least one zergling && atleast one marine alive
			{
				break;
			}
			cout << "A zergling attacks for " << zergling.attack() << " damage." << endl;
			squad.begin()->takeDamage(zergling.attack());
			if (squad.begin()->isAlive())
			{
				cout << " marine lives" << endl;
				cout << "marine current health is " << squad.begin()->health << endl << endl;
			}
			else
			{
				squad.erase(squad.begin());
				cout << "The marine succumbs to his wounds." << endl;
				cout << "the number of marines left is :" << squad.size() << endl << endl;

			}
		}

	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (IsGroupAlive(squad))
	{
		cout << "The Marines win." << endl;
	}
	else
	{
		cout << "The Zerg win." << endl;
	}
	system("pause");
}




