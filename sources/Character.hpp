#pragma once

#include "Point.hpp"
#include <iostream>

namespace ariel {
    class Character {
    private:
        std::string _name;
        Point _location;
    public:
        void setInGame(bool inGame);

    private:
        int _hit_points;
        bool _in_game;

    public:
        Character(std::string &name, Point &location, int hit_points) : _name(name), _location(location),
                                                                        _hit_points(hit_points), _in_game(false) {};

        virtual ~Character() = default;

        bool isAlive() const;

        double distance(const Character *other) const;

        void hit(int points);

        const Point &getLocation() const;

        void setLocation(const Point &location);

        std::string getName() const;

        int getHitPoints() const;

        bool isInGame() const;

        virtual std::string print() const = 0;
    };
}

