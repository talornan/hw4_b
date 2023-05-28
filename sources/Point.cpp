#include "Point.hpp"

namespace ariel
{
    Point::Point(double xcoord, double ycoord) : x(xcoord), y(ycoord) {}

    double Point::distance(Point other) const
    {
        return sqrt(pow((x - other.x), 2) + pow((y - other.y), 2));
    }

    string Point::print() const
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

    Point Point::moveTowards(const Point &src, const Point &dest, double dist)
    {
        if (dist < 0)
            throw invalid_argument("Distance cannot be negative!");
        double currentDistance = src.distance(dest);
        if (currentDistance <= dist)
        {
            return dest;
        }
        else
        {
            double ratio = dist / currentDistance;
            double newX = src.x + (dest.x - src.x) * ratio;
            double newY = src.y + (dest.y - src.y) * ratio;
            return Point(newX, newY);
        }
    }

    bool Point::operator==(const Point &other) const
    {
        return (this->x == other.x) && (this->y == other.y);
    }
}
