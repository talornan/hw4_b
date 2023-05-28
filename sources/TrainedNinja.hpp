#pragma once

#include <iostream>
#include "Ninja.hpp"

namespace ariel
{
// TrainedNinja derived class
class TrainedNinja : public Ninja {
public:
    TrainedNinja(const string& name, const Point& location);

};
}