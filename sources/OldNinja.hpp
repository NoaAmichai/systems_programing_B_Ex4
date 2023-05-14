#pragma once

#include "Ninja.hpp"
class OldNinja : public ariel::Ninja {
    static constexpr int OLD_HIT_POINTS = 150;
    static constexpr int OLD_SPEED = 8;
public:
    OldNinja(std::string name, ariel::Point location) : Ninja(name, location, OLD_HIT_POINTS, OLD_SPEED) {}

    ~OldNinja() override = default;
};
