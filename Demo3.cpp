/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>

using namespace std;

#include "sources/Team.hpp"
#include "sources/smartTeam.hpp"

using namespace ariel;

int main() {
    // Test character isAlive
    Cowboy* character1 = new Cowboy("Character1", *(new Point(0, 0)));
    Ninja* character2 = new YoungNinja("Character2", *(new Point(5, 5)));

    if (character1->isAlive()) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }
    if (character2->isAlive()) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }
    character1->hit(50);
    if (character1->isAlive()) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }
    character2->hit(200);
    if (!character2->isAlive()) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }

    // Test Ninja move
    Ninja* ninja = new YoungNinja("Ninja", Point(0, 0));
    Character* enemy = new TrainedNinja("Enemy", Point(5, 5));

    if (ninja->getLocation().getX() == 0) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }
    if (ninja->getLocation().getY() == 0) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }
    ninja->move(enemy);
    if (ninja->getLocation().getX() == 5) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }
    if (ninja->getLocation().getY() == 5) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }

    // Test Ninja slash
    Ninja* enemy1 = new YoungNinja("Enemy", Point(2, 2));
    Ninja* enemy2 = new YoungNinja("Enemy", Point(0, 0.5));

    if (ninja->getHealth() == 100) {
        cout<<ninja->print()<<endl;
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }
    ninja->slash(enemy1);
    if (enemy1->getHealth() == 100) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }
    ninja->slash(enemy2);
    if (ninja->getHealth() == 100) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Not Correct" << std::endl;
    }
    if (enemy2->getHealth() == 60) {
        std::cout << "Correct" << std::endl;
    } else {
cout << ninja->print() << endl;

// Test Cowboy shoot
Cowboy* cowboyshoot = new Cowboy("Cowboy", Point(0, 0));
Ninja* enemyshoot = new OldNinja("Enemy", Point(5, 5));

if (cowboyshoot->getHealth() == 110) {
    cout << "Correct" << endl;
} else {
    cout << "Not Correct" << endl;
}

cowboyshoot->shoot(enemyshoot);

if (enemyshoot->getHealth() == 140) {
    cout << "Correct" << endl;
} else {
    cout << "Not Correct" << endl;
}

// Test Cowboy hasBullets
Cowboy* cowboyBullets = new Cowboy("Cowboy", Point(0, 0));
Ninja* enemyBullets = new OldNinja("Enemy", Point(5, 5));

if (cowboyBullets->hasboolets()) {
    cout << "Correct" << endl;
} else {
    cout << "Not Correct" << endl;
}

for (int i = 0; i < 5; i++) {
    cowboyBullets->shoot(enemyBullets);

    if (cowboyBullets->hasboolets()) {
        cout << "Correct" << endl;
    } else {
        cout << "Not Correct" << endl;
    }
}

cowboyBullets->shoot(enemyBullets);

if (!cowboyBullets->hasboolets()) {
    cout << "Correct" << endl;
} else {
    cout << "Not Correct" << endl;
}

// Test Cowboy reload
Cowboy* cowboyreload = new Cowboy("Cowboy", Point(0, 0));
Ninja* enemyreload = new OldNinja("Enemy", Point(5, 5));

if (cowboyreload->hasboolets()) {
    cout << "Correct" << endl;
} else {
    cout << "Not Correct" << endl;
}

for (int i = 0; i < 6; i++) {
    cowboyreload->shoot(enemyreload);
}

if (!cowboyreload->hasboolets()) {
    cout << "Correct" << endl;
} else {
    cout << "Not Correct" << endl;
}

cowboyreload->reload();

if (cowboyreload->hasboolets()) {
    cout << "Correct" << endl;
} else {
    cout << "Not Correct" << endl;
}

//test smartTeam
    // Create a SmartTeam with a Cowboy leader
    Cowboy* Hadar = new Cowboy("Hadar", Point(10, 20));
    SmartTeam team(Hadar);

    // Add characters to the team
    Cowboy* Tal = new Cowboy("Tal", Point(15, 25));
    TrainedNinja* Omer = new TrainedNinja("Omer", Point(12, 22));
    OldNinja* Shir = new OldNinja("Shir", Point(9, 18));
    YoungNinja* Michal = new YoungNinja("Michal", Point(11, 21));

    team.add(Tal);
    team.add(Omer);
    team.add(Shir);
    team.add(Michal);

    // Create an enemy team with characters
    Cowboy* eCowboy = new Cowboy("Enemy Cowboy", Point(30, 40));
    TrainedNinja* eNinja = new TrainedNinja("Enemy Ninja", Point(32, 38));

    SmartTeam enemyTeam(eCowboy);
    enemyTeam.add(eNinja);

    // Attack the enemy team
    cout << "----- Battle Start -----" << endl;

    cout << "Team: ";
    team.print();

    cout << "Enemy Team: ";
    enemyTeam.print();

    try
    {
        team.attack(&enemyTeam);

        cout << "Team attacked the enemy team!" << endl;

        cout << "Updated Team: ";
        team.print();

        cout << "Updated Enemy Team: ";
        enemyTeam.print();
    }
    catch (const exception& e)
    {
        cout << "An error occurred during the attack: " << e.what() << std::endl;
    }

    cout << "----- Battle End -----" << std::endl;

    // // Clean up the allocated memory
    // delete leader;
    // delete cowboy1;
    // delete ninja1;
    // delete ninja2;
    // delete ninja3;
    // delete enemyCowboy;
    // delete enemyNinja;

    // return 0;
}


//demo we get
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));


     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
