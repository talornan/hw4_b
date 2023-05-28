#include "Cowboy.hpp"

namespace ariel
{

Cowboy::Cowboy(const string& name, const Point& location)
    : Character(name, const_cast<Point&>(location),110), balls(6) {
}
Cowboy::Cowboy(const Cowboy& other):
 Character(other), balls(other.balls) {}

Cowboy& Cowboy::operator=(const Cowboy& other)
{
	if (this != &other)
	{
		Character::operator=(other);
		balls = other.balls;
	}

	return *this;
}

Cowboy::Cowboy(Cowboy&& other) noexcept: 
Character(move(other)), balls(other.balls)
{
	other.balls = 0;
}

Cowboy& Cowboy::operator=(Cowboy&& other) noexcept
{
	if (this != &other)
	{
		Character::operator=(move(other));
		balls = other.balls;
		other.balls = 0;
	}

	return *this;
}

Cowboy::~Cowboy() {}



void Cowboy::shoot(Character* enemy) {
    /*
    Shoots the enemy if the Cowboy is alive and has bullets remaining.
    Decreases the enemy's hit points by 10 and decrements the bullet count.
    */	if (enemy == nullptr)
		throw invalid_argument("Other character is null!");

	else if (enemy == this)
		throw runtime_error("Cannot shoot yourself!");

	else if (!isAlive())
		throw runtime_error("Cannot shoot while dead!");

	else if (!enemy->isAlive())
		throw runtime_error("Cannot shoot a dead character!");
    if (isAlive() && balls > 0) {
        enemy->hit(10);
       balls--;
    }
}

bool Cowboy::hasboolets() const {
    /*
    Returns true if the Cowboy has balls remaining, false otherwise.
    */

    return balls > 0;
}

void Cowboy::reload() {
    /*
    Reloads the Cowboy's gun by setting the bullet count back to 6.
    */
    if (!isAlive())
		throw runtime_error("Cannot reload while dead!");
    balls = 6;
}



string Cowboy::print() const {
    /*
    Returns a string representation of the Cowboy.
    */

    string info = "Name: " + getName() + ", Hit Points: " + to_string(getHealth()) + ", Location: ";
    info += getLocation().print();
    return info;
}




} 
