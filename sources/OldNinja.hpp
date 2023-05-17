#pragma once

#include "Ninja.hpp"

class OldNinja : public ariel::Ninja {
    static const int OLD_HIT_POINTS {150};
    static const int OLD_SPEED {8};

public:

    OldNinja(std::string name, ariel::Point location) : Ninja(name,OLD_SPEED, location, OLD_HIT_POINTS) {}

//    ~OldNinja() override = default;
};
