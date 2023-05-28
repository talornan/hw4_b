#pragma once

#include <iostream>
#include "Character.hpp"

using namespace std;

namespace ariel
{

class Cowboy : public Character {
private:
    int balls;
    int hitPoints;

public:
    Cowboy(const string& name, const Point& location);

    
			/*
			 * @brief Construct a new Cowboy object.
			 * @param other The other cowboy.
			 * @note This is a copy constructor.
			*/
			Cowboy(const Cowboy& other);

			/*
			 * @brief Construct a new Cowboy object.
			 * @param other The other cowboy.
			 * @note This is a move constructor.
			*/
			Cowboy(Cowboy&& other) noexcept;

			/*
			 * @brief Assigns the cowboy to another cowboy.
			 * @param other The other cowboy.
			 * @return Cowboy& The cowboy after the assignment.
			*/
			Cowboy& operator=(const Cowboy& other);

			/*
			 * @brief Assigns the cowboy to another cowboy.
			 * @param other The other cowboy.
			 * @return Cowboy& The cowboy after the assignment.
			*/
			Cowboy& operator=(Cowboy&& other) noexcept;

			/*
			 * @brief Destroy the Cowboy object.
			*/
			~Cowboy() override;
            
    /*
     * Shoot an enemy character.
     *
     * @param enemy The enemy character.
     */
    void shoot(Character* enemy);

    /*
     * Check if the Cowboy has bullets.
     *
     * @return true if the Cowboy has bullets, false otherwise.
     */
    bool hasboolets() const;

    int getbullets() const {
        return this->balls;
    }

    /*
     * Reload the Cowboy's gun.
     */
    void reload();

    /*
     * Print information about the Cowboy.
     */

	 
    string print() const override;

    // bool operator==(const Cowboy& other) const;

};

} 
