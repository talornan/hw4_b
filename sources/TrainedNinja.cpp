
#include <iostream>
#include "TrainedNinja.hpp"

namespace ariel
{
    // TrainedNinja derived class
    TrainedNinja::TrainedNinja(const string& name, const Point& location)
        : Ninja(name, location,120,12) {}
}