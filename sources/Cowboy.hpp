#pragma once

#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character {
    private:
        int _bullets;
        static const int HIT_POINTS {110};
        static const int MAX_BULLETS {6};

    public:
        Cowboy(std::string name, Point point) : Character(name, point, HIT_POINTS),
                                                _bullets(MAX_BULLETS) {}; // & ?

        ~Cowboy() override = default;

        void shoot(Character *enemy);

        bool hasboolets() const;

        void reload();

        std::string print() const override;

        //Make tidy happy
        Cowboy(const Cowboy&) = delete;
        Cowboy& operator=(const Cowboy&) = delete;
        Cowboy(Cowboy&&) = delete;
        Cowboy& operator=(Cowboy&&) = delete;


    };
}


