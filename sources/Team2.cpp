#include <iostream>
#include "Team2.hpp"

using namespace std;
using namespace ariel;

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::attack(Team *other)
{
	if (other == nullptr)
		throw invalid_argument("Other team is null!");

	else if (other == this)
		throw runtime_error("Cannot attack self team!");

	else if (other->stillAlive() == 0)
		throw runtime_error("Other team is dead!");

	else if (stillAlive() == 0)
		throw runtime_error("This team is dead!");

	// Find a new leader if the current one is dead
	if (!getLeader()->isAlive())
	{
		Character *newLeader = nullptr;
		double minDistance = MAXFLOAT;

		for (Character *member : getMembers())
		{
			double dist = member->distance(getLeader());
			if (member->isAlive() && dist < minDistance)
			{
				newLeader = member;
				minDistance = dist;
			}
		}

		setLeader(newLeader);
	}

	// Find the closest enemy
	Character *closestEnemy = nullptr;
	double minDistance = MAXFLOAT;

	for (Character *member : other->getMembers())
	{
		double dist = member->distance(getLeader());
		if (member->isAlive() && dist < minDistance)
		{
			closestEnemy = member;
			minDistance = dist;
		}
	}

	// Attack the closest enemy
	for (Character *member : getMembers())
	{
		if (!closestEnemy->isAlive())
		{
			if (other->stillAlive() == 0)
			{
				cout << "The enemy team is died!" << endl;
				return;
			}

			double minDistance = MAXFLOAT;

			for (Character *member : other->getMembers())
			{
				double dist = member->distance(getLeader());
				if (member->isAlive() && dist < minDistance)
				{
					closestEnemy = member;
					minDistance = dist;
				}
			}
		}

		if (!member->isAlive())
			continue;

		Cowboy *cowboy = dynamic_cast<Cowboy *>(member);

		if (cowboy != nullptr)
		{
			if (cowboy->hasboolets())
			{
				cowboy->shoot(closestEnemy);
			}
			else
			{
				cowboy->reload();
			}
		}

		else
		{
			Ninja *ninja = dynamic_cast<Ninja *>(member);

			if (ninja != nullptr)
			{
				if (ninja->distance(closestEnemy) <= 1)
				{
					ninja->slash(closestEnemy);
				}
				else
				{
					ninja->move(closestEnemy);
				}
			}
		}
	}
}

void Team2::print() const
{
	cout << "Team Leader: " << getLeader()->getName() << endl;

	for (Character *member : getMembers())
		cout << member->print() << endl;
}