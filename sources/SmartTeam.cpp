#include <algorithm>
#include "SmartTeam.hpp"

using namespace std;

namespace ariel {
    SmartTeam::SmartTeam(Character *_leader) : Team(_leader) {}

    // Custom comparison function for sorting Team based on distance and hit points
    bool compareTeam(Character *a, Character *b, Character *leader) {
        double distanceA = leader->distance(a);
        double distanceB = leader->distance(b);
        if (distanceA != distanceB) {
            return distanceA < distanceB;
        } else {
            return a->getHitPoints() > b->getHitPoints();
        }
    }

    void SmartTeam::print() const {
        //Sort the enemies based on distance from the leader and hit points
        vector<Character *> _members = getTeam();
        std::sort(_members.begin(), _members.end(), [&](Character *a, Character *b) {
            return compareTeam(a, b, getLeader());
        });
        Team::print();
    }


    void SmartTeam::attack(Team *enemies) {
        // Check if the enemy team is null or already defeated
        if (enemies == nullptr) {
            throw std::invalid_argument("Enemies can't be null");
        }
        if (enemies->stillAlive() == 0) {
            throw std::runtime_error("Can't attack a dead team.");
        }

        // Check if attacking team has any living members
        if (stillAlive() == 0) {
            cout << "This team can't attack, all the members are dead" << endl;
            return;
        }

        Character* _leader = getLeader();
        vector<Character*> _members = getTeam();
        // Sort the enemies based on distance from the leader and hit points
        vector<Character *> enemies_team = enemies->getTeam();
        std::sort(enemies_team.begin(), enemies_team.end(), [&](Character *a, Character *b) {
            return compareTeam(a, b, _leader);
        });


        // If the leader isn't alive, find a new leader among the living members
        if (!_leader->isAlive()) {
            _leader = findClosestAliveCharacter(_leader, _members);
            cout << "New leader selected: " << _leader->getName() << endl;
        }

        cout << "Attacking team: " << _leader->getName() << endl;

        // Increment the attack count
        _attackCount++;

        // Find the closest alive enemy to the leader
        Character *closest_enemy = findClosestAliveCharacter(_leader, enemies_team);
        cout << _leader->getName() << " team is attacking " << closest_enemy->getName() << endl;

        // Iterate over the attacking team members
        for (Character *member: _members) {
            if (!member->isAlive()) continue;
            if (enemies->stillAlive() == 0) return; // Check if the enemy team has any living members left

            // Check if the member is a Cowboy
            if (auto *cowboy = dynamic_cast<Cowboy *>(member)) {
                if (cowboy->hasboolets()) {
                    cowboy->shoot(closest_enemy);
                    cout << cowboy->getName() << " shot " << closest_enemy->getName() << endl;
                } else {
                    cowboy->reload();
                    cout << cowboy->getName() << " reloaded" << endl;
                }
            }

                // Check if the member is a Ninja
            else if (auto *ninja = dynamic_cast<Ninja *>(member)) {
                if (ninja->distance(closest_enemy) <= 1) {
                    ninja->slash(closest_enemy);
                    cout << ninja->getName() << " slashed " << closest_enemy->getName() << endl;
                } else {
                    ninja->move(closest_enemy);
                    cout << ninja->getName() << " moved towards " << closest_enemy->getName() << endl;
                }
            }

            // Check if the current victim is dead, and find a new victim if needed
            if (!closest_enemy->isAlive()) {
                closest_enemy = findClosestAliveCharacter(_leader, enemies_team);
                if (!closest_enemy) return; // No more living enemies
                cout << "New victim selected: " << closest_enemy->getName() << endl;
            }
        }
    }
}