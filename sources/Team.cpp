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

    void Team::add(Character *member) {
        if (member->isInGame()) {
            throw std::runtime_error(member->getName() + " is playing in another game right now.");
        } else {
            member->setInGame(true);
        }

        if (_members.size() >= MAX_MEMBERS) {
            throw std::runtime_error("Team is already at maximum capacity");
        }

        // Determine the insertion position based on the type and order of characters
        auto insertPosition = _members.end();
        if (dynamic_cast<Cowboy *>(member)) {
            for (auto it = _members.begin(); it != _members.end(); ++it) {
                if (!dynamic_cast<Cowboy *>(*it)) {
                    insertPosition = it;
                    break;
                }
            }
        }

        // Insert the member at the determined position
        _members.insert(insertPosition, member);
    }
    // Attacks another team
    void Team::attack(Team *enemies) {
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
        Character *closest_enemy = findClosestAliveCharacter(_leader, enemies->_members);
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

    const std::vector<Character *> &Team::getMembers() const {
        return _members;
    }

    void Team::addToMembers(Character *member) {
        _members.push_back(member);
    }


}