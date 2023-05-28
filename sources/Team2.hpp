#pragma once

#include "Team.hpp"

namespace ariel
{
	class Team2 : public Team
	{		
		public:
			/*
			* @brief Construct a new Team2 object.
			* @param leader A pointer to the leader of the team.
			*/
			Team2(Character *leader);

			/*
			* @brief Attack the other team
			* @param other A pointer to the other team
			*/
			void attack(Team *other) override;

			/*
			* @brief Print the team members
			*/
			void print() const override;
	};
}




