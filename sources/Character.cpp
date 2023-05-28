#include "Character.hpp"

namespace ariel
{

Character::Character(const string& name, const Point& location,int hitPoints) 
    : name(name), location(location), hitPoints(hitPoints) ,status(false){}

Character::Character(const Character& other): 
name(other.name), location(other.location),hitPoints(other.hitPoints), status(other.status) {}

Character::Character(Character&& other) noexcept: 
name(move(other.name)), location(other.location), hitPoints(other.hitPoints)
{
	other.hitPoints = 0;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        // Perform the assignment of member variables
        this->name = other.name;
        this->location = other.location;
        this->hitPoints = other.hitPoints;
    }
    return *this;
}

Character& Character::operator=(Character&& other) noexcept
{
	if (this != &other)
	{
		hitPoints = other.hitPoints;
		name = move(other.name);
		other.hitPoints = 0;
	}

	return *this;
}

bool Character::isAlive() const{
    return hitPoints>0;
}

double Character::distance(Character *other) const{
    if (other == nullptr)
		throw invalid_argument("Other character is null!");
    return this->location.distance(other->getLocation());
}


void Character::hit(int damage)  {
    if (damage < 0)
        throw invalid_argument("Power cannot be negative!");

    hitPoints -= damage;
    if (hitPoints <= 0)
		cout << name << " died." << endl;    
}

string Character::print() const {
    std::string result = "Name: " + name + ", Hit Points: " + std::to_string(hitPoints) + ", Location: ";
    result += location.print();
    return result;
}

const Point&Character:: getLocation() const {
        return this->location;
 }


Character :: ~Character(){}

}


