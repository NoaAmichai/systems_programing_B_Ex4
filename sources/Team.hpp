#pragma once

#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Character.hpp"

namespace ariel {
    class Team {
    private:
        static const int MAX_MEMBERS{10};


    public:
        Team(Character *leader) {};

        void add(Character *member) {};

        void attack(Team *enemies) {};

        int stillAlive() const { return 0; };

        std::string print() const { return ""; };


    };


}
