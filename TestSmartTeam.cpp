// #include "doctest.h"

// #include "sources/Character.hpp"
// #include "sources/OldNinja.hpp"
// #include "sources/YoungNinja.hpp"
// #include "sources/TrainedNinja.hpp"
// #include "sources/Cowboy.hpp"
// #include "sources/Team.hpp"
// #include "sources/Team2.hpp"
// #include "sources/smartTeam.hpp"
// #include <random>
// #include <chrono>
// #include <iostream>

// using namespace ariel;
// using namespace std;

// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"
// #include "smartTeam.h"

// TEST_CASE("Test smartTeam class")
// {
//     SUBCASE("Test add function")
//     {
//         // Test adding a valid character
//         Character* leader = new Cowboy("John");
//         smartTeam team(leader);
//         Character* fighter = new Cowboy("Mike");
//         CHECK_NOTHROW(team.add(fighter));

//         // Test adding a character already in a team
//         CHECK_THROWS(team.add(fighter));

//         // Clean up
//         delete leader;
//         delete fighter;
//     }

//     SUBCASE("Test attack function")
//     {
//         // Test attacking another team
//         Character* leader = new Cowboy("John");
//         smartTeam team(leader);
//         Character* enemyLeader = new Ninja("Sam");
//         smartTeam enemyTeam(enemyLeader);
//         CHECK_NOTHROW(team.attack(&enemyTeam));

//         // Test attacking self team
//         CHECK_THROWS(team.attack(&team));

//         // Test attacking a dead team
//         enemyTeam.kill();
//         CHECK_THROWS(team.attack(&enemyTeam));

//         // Clean up
//         delete leader;
//         delete enemyLeader;
//     }

//     SUBCASE("Test print function")
//     {
//         Character* leader = new Cowboy("John");
//         smartTeam team(leader);
//         Character* fighter1 = new Cowboy("Mike");
//         Character* fighter2 = new Ninja("Sam");
//         team.add(fighter1);
//         team.add(fighter2);
//         team.print();

//         // Clean up
//         delete leader;
//         delete fighter1;
//         delete fighter2;
//     }
// }
