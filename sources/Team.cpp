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
        // If leader isn't alive, generate new leader
        if (!_leader->isAlive()) {
            Character *new_leader = findClosestCharacter(_leader, _members);
            _leader = new_leader;
        }

        while (stillAlive() > 0 && enemies->stillAlive() > 0) {
            //Find the closest enemy to the leader
            Character *victim = findClosestCharacter(_leader, enemies->_members);

            // Attack the victim
            while (victim->isAlive()) {
                if(auto* cowboy = findNextCowboyWithBullets()){
                    cowboy->shoot(victim);
                    break;
                }
                else{ //There isn't any cowboy alive and with bullets


                }

            }
//            enemies->_members.emplace_back(victim);

        }


    }

    // Returns the number of alive members in the team
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

    // Finds the next alive cowboy with bullets
    Cowboy *Team::findNextCowboyWithBullets() {
        for (Character *member: _members) {
            // Check if the member is a cowboy and has bullets
            if (auto *cowboy = dynamic_cast<Cowboy *>(member)) { // cowboy will be null if the member isn't cowboy
                if (cowboy->isAlive() && cowboy->hasboolets()) {
                    return cowboy;
                }
            }
        }
        return nullptr;
    }
}

