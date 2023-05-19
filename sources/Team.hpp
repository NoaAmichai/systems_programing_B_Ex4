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
        Character *_leader;
        std::vector<Character *> _members;

    protected:
        static const int MAX_MEMBERS{10};
        int _attackCount;
    public:
        Team(Character *leader);

        virtual ~Team();

        virtual void add(Character *member);

        virtual void attack(Team *enemies);

        int stillAlive() const;

        virtual void print() const;

        static Character *findClosestAliveCharacter(Character *source, std::vector<Character *> &chars);

        //Because Tidy does not agree '_members' and '_leader' to be protected
        std::vector<Character *> getTeam() const;
        void addToMembers(Character *member);
        Character *getLeader() const;

        //Make tidy happy
        Team(const Team &) = delete;
        Team &operator=(const Team &) = delete;
        Team(Team &&) = delete;
        Team &operator=(Team &&) = delete;

        int getAttackCount() const;
    };
}
