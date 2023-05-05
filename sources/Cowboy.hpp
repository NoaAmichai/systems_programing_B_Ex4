#pragma once

#include "Character.hpp"

namespace ariel {

    class Cowboy : public Character {
    private:
        int _bullets;


    public:
        Cowboy(std::string name, Point &point) : Character(name, point, 11), _bullets(6) {}; // & ?

        void shoot(Character *enemy);

        bool hasBullets() const;

        void reload();

        std::string print() const override;
    };
}


