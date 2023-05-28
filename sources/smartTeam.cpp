#include <iostream>
#include "smartTeam.hpp"

using namespace std;
using namespace ariel;

SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

void SmartTeam::add(Character *fighter)
{
    getMembers().push_back(fighter);
    sortCharactersByHitPoints();
}



void SmartTeam::attack(Team *enemyTeam)
{
    if (enemyTeam == nullptr)
        throw std::invalid_argument("Enemy team is null");

    else if (enemyTeam == this)
        throw std::runtime_error("Team cannot attack itself");

    else if (enemyTeam->stillAlive() == 0)
        throw std::runtime_error("Enemy team is defeated");

    else if (stillAlive() == 0)
        throw std::runtime_error("Team is defeated");

    // Find a new leader if the current one is dead
	else if (!getLeader()->isAlive())
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

	Character *target = findTarget(enemyTeam);
	cout << "The target: " << target->print() << endl;


	for (Character *member : getMembers())
	{
		if (!target->isAlive())
		{
			if (enemyTeam->stillAlive() == 0)
			{
				cout << "The enemy team is died!";
				return;
			}

			target = findTarget(enemyTeam);
			cout<<"the target";
			cout<<target->print()<<endl;
		}

		if (!member->isAlive())
		cout << "member is dead";
			continue;

		Cowboy *cowboy = dynamic_cast<Cowboy *>(member);

		if (cowboy != nullptr)
		{
			if (cowboy->hasboolets()){
				cowboy->shoot(target);
				cout<<"the attacker:"<<cowboy->print()<<endl;

			}
				
			else
			{
				cowboy->reload();
				cout<<"the attacker:"<<cowboy->print()<<endl;

			}
				
		}

		else
		{
			Ninja *ninja = dynamic_cast<Ninja *>(member);

			if (ninja != nullptr)
			{
				if (ninja->distance(target) <= 1){
					cout<<"the attacker:"<<ninja->print()<<endl;
					ninja->slash(target);

				}

				else{
					ninja->move(target);
					cout<<"the attacker:"<<cowboy->print()<<endl;

				}

			}
		}
	}
}


Character *SmartTeam::findTarget(Team *enemyTeam)
{
    Character *target = nullptr;
    int minHitPoints = std::numeric_limits<int>::max();

    for (Character *member : enemyTeam->getMembers())
    {
        if (!member->isAlive())
        {
            continue;
        }

        int hp = member->getHealth();
        if (hp < minHitPoints && member->isAlive())
        {
            minHitPoints = hp;
            target = member;
        }
    }

    return target;
}

void SmartTeam::sortCharactersByHitPoints()
{
    std::sort(getMembers().begin(), getMembers().end(), [](Character *p1, Character *p2)
              { return p1->getHealth() > p2->getHealth(); });
}

void SmartTeam::swapPlayers(Character *figther1, Character *figther2)
{
    std::iter_swap(std::find(getMembers().begin(), getMembers().end(), figther1),
                   std::find(getMembers().begin(), getMembers().end(), figther2));
}
