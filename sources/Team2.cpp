#include "Team2.hpp"

namespace ariel {

    Team2::Team2(Character *_leader) : Team(_leader) {}

    void Team2::add(Character *member) {
        if (member->isInGame()) {
            throw std::runtime_error(member->getName() + " is playing in another game right now.");
        } else {
            member->setInGame(true);
        }

        if (getTeam().size() >= MAX_MEMBERS) {
            throw std::runtime_error("Team is already at maximum capacity");
        }
        addToMembers(member);
    }
}