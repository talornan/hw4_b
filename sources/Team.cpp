#include "Team.hpp"

namespace ariel
{
    // Constructor
    Team::Team(Character *leader) : leader(leader)
    {
        if (leader->getStatus())
            throw runtime_error("In team already!");
        members.push_back(leader);

        leader->setStatus(true);
    }

    // Default Constructor
    Team::Team() {}

    Team::Team(const Team &other)
    {
        for (auto &member : other.members)
        {
            this->members.push_back(member);
        }
        this->leader = other.leader;
    }

    Team &Team::operator=(const Team &other)
    {
        if (this == &other)
        {
            return *this;
        }

        for (auto &member : this->members)
        {
            delete member;
        }
        this->members.clear();

        for (auto &member : other.members)
        {
            this->members.push_back(member);
        }

        this->leader = other.leader;
        return *this;
    }

    Team::Team(Team &&other) noexcept
    {
        for (auto &member : other.members)
        {
            this->members.push_back(member);
        }
        other.members.clear();

        this->leader = other.leader;
        other.leader = nullptr;
    }

    Team &Team::operator=(Team &&other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        for (auto &member : this->members)
        {
            delete member;
        }
        this->members.clear();
        for (auto &member : other.members)
        {
            this->members.push_back(member);
        }
        other.members.clear();

        this->leader = other.leader;
        other.leader = nullptr;

        return *this;
    }

    Team::~Team()
    {
        for (auto &member : this->members)
        {
            delete member;
        }
        this->members.clear();
    }

    // Add a Fighter (Ninja or Cowboy) to the team
    void Team::add(Character *fighter)
    {
        if (members.size() >= 10)
        {
            throw runtime_error("Exceeded maximum number of participants in the team");
        }
        // Check if the character already exists in the team
        if (fighter->getStatus())
        {
            throw runtime_error("In team already!");
        }
        members.push_back(fighter);
        fighter->setStatus(true);
    }

    void Team::attack(Team *enemyTeam)
    {
        if (enemyTeam == nullptr)
            throw invalid_argument("enemy team is null!");

        else if (enemyTeam == this)
            throw runtime_error("Cannot attack self team!");

        else if (enemyTeam->stillAlive() == 0)
            throw runtime_error("Other team is dead!");

        else if (stillAlive() == 0)
            throw runtime_error("Team is dead!");

        // Find a new leader if the current one is dead
        if (!leader->isAlive())
        {
            Character *newLeader = nullptr;
            double minDistance = MAXFLOAT;

            for (Character *member : members)
            {
                double dist = member->distance(leader);
                if (member->isAlive() && dist < minDistance)
                {
                    newLeader = member;
                    minDistance = dist;
                }
            }

            leader = newLeader;
        }

        // Find the closest enemy
        Character *closestEnemy = nullptr;
        double minDistance = MAXFLOAT;

        for (Character *member : enemyTeam->members)
        {
            double dist = member->distance(leader);
            if (member->isAlive() && dist < minDistance)
            {
                closestEnemy = member;
                minDistance = dist;
            }
        }

        // Attack the closest enemy
        for (Character *member : members)
        {
            if (!closestEnemy->isAlive())
            {
                if (enemyTeam->stillAlive() == 0)
                {
                    cout << "The enemy team is died!" << endl;
                    return;
                }
                
                double minDistance = MAXFLOAT;

                for (Character *member : enemyTeam->members)
                {
                    double dist = member->distance(leader);
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
        }

        for (Character *member : members)
        {
            if (!closestEnemy->isAlive())
            {
                if (enemyTeam->stillAlive() == 0)
                {
                    cout << "The enemy team is died!" << endl;
                    return;
                }
                
                double minDistance = MAXFLOAT;

                for (Character *member : enemyTeam->members)
                {
                    double dist = member->distance(leader);
                    if (member->isAlive() && dist < minDistance)
                    {
                        closestEnemy = member;
                        minDistance = dist;
                    }
                }
            }

            if (!member->isAlive())
                continue;

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

    // Check if the team is still alive
    int Team::stillAlive() const
    {
        {
            int alive = 0;

            for (Character *member : members)
            {
                if (member->isAlive())
                    alive++;
            }

            return alive;
        }
    }

    // Print the details of the team
    void Team::print() const
    {
        cout << "Members: " << endl;
        for (Character *member : members)
        {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);

            if (cowboy != nullptr)
            {
                cout << "Cowboy: " << cowboy->print() << endl;
            }
        }

        for (Character *member : members)
        {
            Ninja *ninja = dynamic_cast<Ninja *>(member);

            if (ninja != nullptr)
            {
                cout << "Cowboy: " << ninja->print() << endl;
            }
        }
    }
}