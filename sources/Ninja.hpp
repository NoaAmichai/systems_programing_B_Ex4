#pragma once

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {


    public:
        Ninja(std::string name, Point location) : Character(name, location) {}

        void move(Character const *enemy);

        void slash(Character *enemy);

        void print() const;
    };


}

