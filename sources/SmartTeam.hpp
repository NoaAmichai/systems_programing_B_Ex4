#pragma once

#include "Team.hpp"

namespace ariel {
    class SmartTeam : public Team {

    public:
        SmartTeam(Character *_leader);

//        void add(Character *member) override;

        void attack(Team *enemies) override;

        void print() const override;

    };
}

