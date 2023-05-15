#pragma once

#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character {
    private:
        int _bullets;
        static constexpr int HIT_POINTS = 110; // ?

    public:
        Cowboy(std::string name, Point point) : Character(name, point, HIT_POINTS),
                                                _bullets(6) {}; // & ?

        ~Cowboy() override = default;

        void shoot(Character *enemy);

        bool hasboolets() const;

        void reload();

        std::string print() const override;


    };
}


