#pragma once

#include "Ninja.hpp"

class TrainedNinja : public ariel::Ninja {
    static const int TRAINED_HIT_POINTS {120};
    static const int TRAINED_SPEED {12};

public:
    TrainedNinja(std::string name, ariel::Point location) : Ninja(name, TRAINED_SPEED, location, TRAINED_HIT_POINTS) {}

//    ~TrainedNinja() override = default;
};