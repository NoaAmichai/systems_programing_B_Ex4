#pragma once

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class OldNinja : public Ninja {

    public:
        OldNinja(std::string name, Point point) : Ninja(name, point) {}
    };

}

