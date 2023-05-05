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

        void move(Character const *enemy);

        void slash(Character *enemy);

        void print() const override;
    };

    class YoungNinja : public Ninja {
    public:
        YoungNinja(std::string name, Point location) : Ninja(name, location, 100, 14) {}
    };

    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(std::string name, Point location) : Ninja(name, location, 120, 12) {}
    };

    class OldNinja : public Ninja {
    public:
        OldNinja(std::string name, Point location) : Ninja(name, location, 150, 8) {}
    };


}

