#pragma once

#include <vector>
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Character.hpp"

namespace ariel {
    class Team {
    private:
        static const int MAX_MEMBERS{10};
        std::vector<Character *> _members;
        Character *_leader;
        int current_members;

    public:
        Team(Character *leader);

        ~Team();

        void add(Character *member);

        void attack(Team *enemies);

        int stillAlive() const;

        void print() const;

        static Character *findClosestCharacter(Character* source, std::vector<Character*>& chars);

        Cowboy* findNextCowboyWithBullets();



    };


}
