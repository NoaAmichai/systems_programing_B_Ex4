#pragma once

#include "Ninja.hpp"

class TrainedNinja : public ariel::Ninja {
    static constexpr int TRAINED_HIT_POINTS = 120;
    static constexpr int TRAINED_SPEED = 12;
public:
    TrainedNinja(std::string name, ariel::Point location) : Ninja(name, location, TRAINED_HIT_POINTS, TRAINED_SPEED) {}

    ~TrainedNinja() override = default;
};