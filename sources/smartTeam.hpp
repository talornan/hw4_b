#pragma once

#include "Team.hpp"

namespace ariel
{
	class SmartTeam : public Team
	{
    public:
 
    /*
	* @brief Construct a new SmartTeam object.
	* @param leader A pointer to the leader of the team.
	*/
	SmartTeam(Character *leader);

    /*
     * @brief Adds a fighter to the team.
     * 
     * The fighter is added to the team's list of fighters and the fighters
     * are sorted by hit points in descending order.
     * 
     * @param fighter A pointer to the fighter to be added.
     */
    void add(Character* fighter) override;

    /*
     * @brief Attacks the enemy team.
     * 
     * Finds the target with the lowest hit points in the enemy team
     * and deals damage to it using the team's attack power.
     * 
     * @param enemyTeam A pointer to the enemy team to attack.
     */
    void attack(Team* enemyTeam) override;

    /*
     * @brief Finds the target with the lowest hit points in the enemy team.
     * 
     * Searches for the player in the enemy team with the lowest hit points
     * who is not yet defeated.
     * 
     * @param enemyTeam A pointer to the enemy team.
     * @return A pointer to the target player, or nullptr if no valid target is found.
     */
    Character* findTarget(Team* enemyTeam);

    /*
     * @brief Sorts the players in the team by hit points in descending order.
     */
    void sortCharactersByHitPoints();

private:
    /*
     * @brief Swaps the positions of two players in the team.
     * 
     * @param fighter1 A pointer to the first player.
     * @param fighter2 A pointer to the second player.
     */
    void swapPlayers(Character* fighter1, Character* fighter2);
};


}
