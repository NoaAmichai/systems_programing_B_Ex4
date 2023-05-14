#pragma once

#include "Ninja.hpp"

class YoungNinja : public ariel::Ninja {
private:
    static constexpr int YOUNG_HIT_POINTS = 140;
    static constexpr int YOUNG_SPEED = 10;

public:
    YoungNinja(std::string name, ariel::Point location) : Ninja(name, location, YOUNG_HIT_POINTS, YOUNG_SPEED) {}

    ~YoungNinja() override = default;
};
