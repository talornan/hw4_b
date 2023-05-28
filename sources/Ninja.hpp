#pragma once

#include <iostream>
#include "Character.hpp"

namespace ariel
{

class Ninja : public Character {
private:
    int speed;
    int health;

public:
    /*
     * Constructor for the Ninja class.
     *
     * @param name The name of the ninja.
     * @param location The initial location of the ninja.
     * @param speed The speed of the ninja.
     */
    Ninja(const string& name, const Point& location,int health, int speed);

    /*
     * Move towards an enemy character.
     *
     * @param enemy The enemy character.
     */
    virtual void move(Character* enemy);

    /*
     * Perform a slashing attack on an enemy character.
     *
     * @param enemy The enemy character.
     */
    virtual void slash(Character* enemy);

    /*
     * Print information about the ninja.
     */
    string print() const override;
};

}
