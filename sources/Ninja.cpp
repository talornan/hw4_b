#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(const string& name, const Point& location,  int health,int speed)
        : Character(name, const_cast<Point&>(location),health), speed(speed) {}


    void Ninja::move(Character* enemy) {
        if (enemy == nullptr)
            throw invalid_argument("Other character is null!");

        else if (enemy == this)
            throw invalid_argument("Cannot move to yourself!");

        else if (!isAlive())
            throw runtime_error("Cannot move while dead!");
    
        Point newLocation = Point::moveTowards(getLocation(), enemy->getLocation(), speed);
        setLocation(newLocation);
    }

    void Ninja::slash(Character* enemy) {
        if (enemy == nullptr)
		throw invalid_argument("Other character is null!");

        else if (enemy == this)
            throw runtime_error("Cannot slash yourself!");

        else if (!isAlive())
            throw runtime_error("Cannot slash while dead!");

        else if (!enemy->isAlive())
            throw runtime_error("Cannot slash a dead character!");
        double dist = getLocation().distance(enemy->getLocation());
        if (isAlive() && dist <= 1.0) {
            enemy->hit(40);
        }
    }

    string Ninja::print() const {
        if (!isAlive()) {
            return "Name: N (" + getName() + "), Location: " + getLocation().print();
        }
        return "Name: N " + getName() + ", HP: " + to_string(getHealth()) + ", Location: " + getLocation().print();
    }

}
