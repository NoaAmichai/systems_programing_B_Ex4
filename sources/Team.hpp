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
    protected:
        static const int MAX_MEMBERS{10};
    private:
        std::vector<Character *> _members;
        Character *_leader;

    public:
        Team(Character *leader);

        virtual ~Team();

        virtual void add(Character *member);

        void attack(Team *enemies);

        int stillAlive() const;

        void print() const;

        static Character *findClosestAliveCharacter(Character *source, std::vector<Character *> &chars);

        //Because Tidy does not like _members to be protected
        const std::vector<Character *> &getMembers() const;

        void addToMembers(Character *member);

        //Make tidy happy
        Team(const Team &) = delete;
        Team &operator=(const Team &) = delete;
        Team(Team &&) = delete;
        Team &operator=(Team &&) = delete;
    };
}
