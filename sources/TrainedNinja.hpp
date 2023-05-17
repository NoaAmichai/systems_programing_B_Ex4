#pragma once

#include "Ninja.hpp"

#define TRAINED_HIT_POINTS 120
#define TRAINED_SPEED 12

class TrainedNinja : public ariel::Ninja {

public:
    TrainedNinja(std::string name, ariel::Point location) : Ninja(name, location, TRAINED_HIT_POINTS, TRAINED_SPEED) {}

    ~TrainedNinja() override = default;
};