#pragma once

#include "Point.hpp"
#include <iostream>

namespace ariel {
    class Character {
    private:
        std::string _name;
        Point _location;
        int _hit_points;

    public:
        Character(std::string &name, Point &location, int hit_points) : _name(name), _location(location),
                                                                        _hit_points(hit_points) {};

        // ? virtual ~Character()= default;

        bool isAlive() const;

        double distance(const Character &other) const;

        void hit(int points);

        const Point &getLocation() const;

        std::string getName() const;

        virtual void print() const; //TODO check if virtual needed


    };
}

