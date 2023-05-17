#pragma once

#include "Ninja.hpp"

#define OLD_HIT_POINTS  150
#define OLD_SPEED  8

class OldNinja : public ariel::Ninja {

public:
    OldNinja(std::string name, ariel::Point location) : Ninja(name, location, OLD_HIT_POINTS, OLD_SPEED) {}

    ~OldNinja() override = default;
};
