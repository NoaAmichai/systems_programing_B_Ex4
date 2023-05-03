#pragma once

#include "Point.hpp"
#include <iostream>

namespace ariel {
    class Character {
    private:
        std::string _name;
        Point _location;
        int hit_point;

    public:
        Character(std::string name, Point location) : _name(name), _location(location) , hit_point(0){};

        bool isAlive();

        double distance(const Character &other) const;

        void hit(int points);

        std::string getName() const;

        Point &getLocation() const;

        void print();

    };
}

