#include "Team.hpp"
#include <climits>

using namespace std;
namespace ariel {

    // Constructor
    Team::Team(Character *leader) : _leader(leader), _members(0) {
        add(_leader);
    }

    // Destructor
    Team::~Team() {
        for (Character *member: _members) {
            delete member;
        }
    }

    // Adds a member to the team
    void Team::add(Character *member) {
        if (member->isInGame()) {
            throw std::runtime_error(member->getName() + " is playing in another game right now.");
        } else member->setInGame(true);
        if (_members.size() < MAX_MEMBERS) {
            _members.push_back(member);
        } else throw std::runtime_error("Team is already at maximum capacity");
    }

// Attacks another team
    void Team::attack(Team* enemies) {
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

        cout << "Attacking team: " << _leader->getName() << endl;

        // If the leader isn't alive, find a new leader among the living members
        if (!_leader->isAlive()) {
            _leader = findClosestAliveCharacter(_leader, _members);
            cout << "New leader selected: " << _leader->getName() << endl;
        }

        // Find the closest alive enemy to the leader
        Character* closest_enemy = findClosestAliveCharacter(_leader, enemies->_members);
        cout << _leader->getName() << " team is attacking " << closest_enemy->getName() << endl;

        // Iterate over the attacking team members
        for (Character* member : _members) {
            if (!member->isAlive()) continue;
            if (enemies->stillAlive() == 0) return; // Check if enemy team has any living members left

            // Check if the member is a Cowboy
            if (auto* cowboy = dynamic_cast<Cowboy*>(member)) {
                if (cowboy->hasboolets()) {
                    cowboy->shoot(closest_enemy);
                    cout << cowboy->getName() << " shot " << closest_enemy->getName() << endl;
                } else {
                    cowboy->reload();
                    cout << cowboy->getName() << " reloaded" << endl;
                }
            }

                // Check if the member is a Ninja
            else if (auto* ninja = dynamic_cast<Ninja*>(member)) {
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
                closest_enemy = findClosestAliveCharacter(_leader, enemies->_members);
                if (!closest_enemy) return; // No more living enemies
                cout << "New victim selected: " << closest_enemy->getName() << endl;
            }
        }
    }



    // Returns the number of living members in the team
    int Team::stillAlive() const {
        int count = 0;
        for (Character *member: _members) {
            if (member->isAlive()) {
                count++;
            }
        }
        return count;
    }

    // Prints the information of all members of the team
    void Team::print() const {
        std::string str;
        for (Character *member: _members) {
            str += member->print();
        }
        cout << str;
    }

    // Finds the closest alive character to the source character
    Character *Team::findClosestAliveCharacter(Character *source, vector<Character *> &chars) {
        Character *closet = nullptr;
        double min_distance = INT_MAX;
        for (Character *member: chars) {
            // Check that the member is still alive and that it is not the source
            if (member == source || !member->isAlive()) continue;

            double current_distance = source->distance(member);
            if (min_distance > current_distance) {
                closet = member;
                min_distance = current_distance;
            }
        }
        return closet;
    }

    // Finds the next living cowboy with bullets
    Cowboy *Team::findNextCowboyWithBullets() {
        for (Character *member: _members) {
            // Check if the member is a cowboy and has bullets
            auto *cowboy = dynamic_cast<Cowboy *>(member); // If it's not a Cowboy, cowboy will be null.
            if (!cowboy) {
                continue;
            }
            // If the cowboy is alive and doesn't have bullets, reload
            if (cowboy->isAlive() && !cowboy->hasboolets()) {
                cowboy->reload();
            }
                // If the cowboy is alive and has bullets
            else if (cowboy->isAlive() && cowboy->hasboolets()) {
                return cowboy;
            }
        }
        return nullptr;
    }

    //Find the next living ninja that is also 1 meter close
    Ninja *Team::findNextNinja(Character *closest_enemy) {
        for (Character *member: _members) {
            // Check if the member is a ninja and close enough
            auto *ninja = dynamic_cast<Ninja *>(member); // If it's not a Ninja, ninja will be null.
            if (!ninja) {
                continue;
            }

            // If the ninja is alive and not close enough, move ninja toward the closest enemy
            if (ninja->isAlive() && (ninja->distance(closest_enemy) > 1)) {
                ninja->move(closest_enemy);
            }
                // If the ninja is alive and close enough
            else if (ninja->isAlive() && (ninja->distance(closest_enemy) <= 1)) {
                return ninja;
            }
        }
        return nullptr;
    }
}

