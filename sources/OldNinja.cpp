#include <iostream>
#include "OldNinja.hpp"

namespace ariel
{
    // OldNinja derived class
    OldNinja::OldNinja(const string& name, const Point& location)
        : Ninja(name, location,150,8) {}
}