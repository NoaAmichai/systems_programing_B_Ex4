#pragma once

#include "Character.hpp"

namespace ariel {
    constexpr int HIT_POINTS = 110;
    constexpr int BULLETS = 6;

    class Cowboy : public Character {
    private:
        int _bullets;


    public:
        Cowboy(std::string name, Point &point) : Character(name, point, HIT_POINTS), _bullets(BULLETS) {}; // & ?

        ~Cowboy() override = default;

        void shoot(Character *enemy);

        bool hasBullets() const;

        void reload();

        std::string print() const override;
    };
}


