#pragma once

#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Character.hpp"

namespace ariel {
    class Team {
    private:
        static const int MAX_MEMBERS {10};


    public:
        Team(Character* leader){};
        void add(Character* member);
        void attack(Team* enemies);

        int stillAlive() const;
        void print() const;


    };


}
