#pragma once

#include "Character.hpp"

namespace ariel {

    class Ninja : public Character {

    private:
        int _speed;

    public:
        Ninja(std::string &name, Point &location, int hit_points, int speed) : Character(name,
                                                                                         location,
                                                                                         hit_points),
                                                                               _speed(speed) {}

        ~Ninja() override = default;

        void move(Character const *enemy);

        void slash(Character *enemy);

        std::string print() const override;

    };


}

