#pragma once

#include "Ninja.hpp"

#define YOUNG_HIT_POINTS 100
#define YOUNG_SPEED 14

class YoungNinja : public ariel::Ninja {

public:
    YoungNinja(std::string name, ariel::Point location) : Ninja(name, location, YOUNG_HIT_POINTS, YOUNG_SPEED) {}

    ~YoungNinja() override = default;
};
