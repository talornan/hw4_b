#pragma once

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

namespace ariel
{
    class Team
    {

    private:
        vector<Character *> members;
        Character *leader;

    public:
        // Constructor
        Team(Character *leader);
        // Default Constructor
        Team();
        // Copy Constructor
        Team(const Team &other);
        // Copy Assignment Operator
        Team &operator=(const Team &other);
        // Move Constructor
        Team(Team &&other) noexcept;
        // Move Assignment Operator
        Team &operator=(Team &&other) noexcept;
        // Destructor
        virtual ~Team();

        // getter and setter methods
        
        /*
         * @brief Returns a reference to the team's list of members.
         * @note Const method version.
        */
        const vector<Character *> &getMembers() const
        {
            return members;
        }

        /*
         * @brief Returns a reference to the team's list of members.
         * @note Non-cost method version.
        */
        vector<Character *> &getMembers()
        {
            return members;
        }
        void setLeader(Character *leader)
        {
            this->leader = leader;
        }
        Character *getLeader() const
        {
            return this->leader;
        }

        // Add a Fighter (Ninja or Cowboy) to the team
        virtual void add(Character *fighter);
        // Attack an enemy team
        virtual void attack(Team *enemyTeam);
        // Check how many fighters of the team are still alive
        int stillAlive() const;
        // Print the details of the team
        virtual void print() const;
    };
}
