#pragma once

#include "Character.hpp"

namespace ariel {

    class Ninja : public Character {

    private:
        int _speed;

    public:
        Ninja(std::string &name, int speed, Point &location, int hit_points) : Character(name,
                                                                                         location,
                                                                                         hit_points),
                                                                               _speed(speed) {}

        ~Ninja() override = default;

        void move(Character const *enemy);

        void slash(Character *enemy);

        std::string print() const override;

        //Make tidy happy
        Ninja(const Ninja &) = delete;
        Ninja &operator=(const Ninja &) = delete;
        Ninja(Ninja &&) = delete;
        Ninja &operator=(Ninja &&) = delete;

    };


}

