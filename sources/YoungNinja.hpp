#pragma once

#include "Ninja.hpp"

class YoungNinja : public ariel::Ninja {
    static const int YOUNG_HIT_POINTS{100};
    static const int YOUNG_SPEED{14};

public:
    YoungNinja(std::string name, ariel::Point location) : Ninja(name, YOUNG_SPEED, location, YOUNG_HIT_POINTS) {}

//    ~YoungNinja() override = default;
};
