#pragma once

#include "Character.hpp"

namespace ariel {
    constexpr int YOUNG_HIT_POINTS = 100;
    constexpr int YOUNG_SPEED = 14;
    constexpr int TRAINED_HIT_POINTS = 120;
    constexpr int TRAINED_SPEED = 12;
    constexpr int OLD_HIT_POINTS = 150;
    constexpr int OLD_SPEED = 8;

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

    class YoungNinja : public Ninja {
    public:
        YoungNinja(std::string name, Point location) : Ninja(name, location, YOUNG_HIT_POINTS, YOUNG_SPEED) {}

        ~YoungNinja() override = default;
    };

    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(std::string name, Point location) : Ninja(name, location, TRAINED_HIT_POINTS, TRAINED_SPEED) {}

        ~TrainedNinja() override = default;
    };

    class OldNinja : public Ninja {
    public:
        OldNinja(std::string name, Point location) : Ninja(name, location, OLD_HIT_POINTS, OLD_SPEED) {}

        ~OldNinja() override = default;
    };


}

