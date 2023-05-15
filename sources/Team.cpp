#include "Team.hpp"
#include <climits>

using namespace std;
namespace ariel {

    // Constructor
    Team::Team(Character *leader) : _leader(leader), _members(0), current_members(1) {
        _members.push_back(_leader);
    }

    // Destructor
    Team::~Team() {
        for (Character *member: _members) {
            delete member;
        }
    }

    // Adds a member to the team
    void Team::add(Character *member) {
        if (current_members < MAX_MEMBERS) {
            ++current_members;
            _members.push_back(member);
        } else throw runtime_error("Team is already at maximum capacity");
    }

    // Attacks another team
    void Team::attack(Team *enemies) { //TODO !
        if (stillAlive() == 0) {
            cout << "This team can't attack, all the members are dead" << endl;
            return;
        }
        // If the leader isn't alive, generate a new one
        if (!_leader->isAlive()) {
            Character *new_leader = findClosestCharacter(_leader, _members);
            _leader = new_leader;
        }

        while (stillAlive() > 0 && enemies->stillAlive() > 0) {
            // Find the closest alive enemy
            Character *closest_enemy = findClosestCharacter(_leader, enemies->_members);

            // Attack the closest alive enemy
            while (closest_enemy->isAlive()) {
                // Find cowboy alive and with bullets
                if (auto *cowboy = findNextCowboyWithBullets()) {
                    cowboy->shoot(closest_enemy);
                    break;
                } else if () {// Find Ninja that is in distance < 1

                }
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
    Character *Team::findClosestCharacter(Character *source, vector<Character *> &chars) {
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
            auto *cowboy = dynamic_cast<Cowboy *>(member); // If it's not a cowboy, cowboy will be null.
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
}

