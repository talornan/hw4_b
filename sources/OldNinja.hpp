#pragma once

#include <iostream>
#include "Ninja.hpp"

namespace ariel
{
// OldNinja derived class
class OldNinja : public Ninja {
public:
    OldNinja(const string& name, const Point& location);
};
}