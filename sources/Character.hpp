#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character {
    private:
        Point location;
        string name;
        int hitPoints;
        bool status;

    public:
    Character(const string& name, const Point& location,int hitPoints);
    /*
			 * @brief Construct a new Character object.
			 * @param other The other character.
			 * @note This is a copy constructor.
			*/
			Character(const Character& other);

			/*
			 * @brief Construct a new Character object.
			 * @param other The other character.
			 * @note This is a move constructor.
			*/
			Character(Character&& other) noexcept;

			/*
			 * @brief Overloads the assignment operator.
			 * @param other The other character.
			 * @return The character after the assignment.
			*/
			Character& operator=(const Character& other);

			/*
			 * @brief Overloads the assignment operator.
			 * @param other The other character.
			 * @return The character after the assignment.
			*/
			Character& operator=(Character&& other) noexcept;

        //getter And setter methods

        string getName() const{
            return this->name;
        }

        void setName(string newName){
            this->name = std::move(newName);
        }

        const Point& getLocation() const;


        virtual void setLocation(const Point& newLocation){
            this->location = newLocation;
        }

        virtual int getHealth() const {
            return this->hitPoints;
        }

        virtual void setHitPoints(int newHitPoints){
            this->hitPoints=newHitPoints;
        }
        bool getStatus() const {
            return this->status;
        }

        void setStatus(bool ans) {
            this->status = ans;
        }

        


        /*
         * Check if theCharacter is alive.
         *
         * @return true if theCharacter is alive, false otherwise.
         */
        bool isAlive() const;

        /*
         * Calculate the distance between twoCharacters.
         *
         * @param other The otherCharacter.
         * @return The distance between theCharacters.
         */
        double distance(Character *other) const;


        /*
         * Print information about theCharacter.
         */
        virtual string  print() const;

        /*
         * Inflict damage to theCharacter.
         *
         * @param damage The amount of damage to inflict.
         */
        void hit(int damage) ;

        // Destructor
        virtual ~Character();
    };

} 
