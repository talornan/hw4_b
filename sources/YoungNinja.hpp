#pragma once

#include <iostream>
#include "Ninja.hpp"

namespace ariel
{

// YoungNinja derived class
class YoungNinja : public Ninja {

public:
    YoungNinja(const string& name, const Point& location);

};
}