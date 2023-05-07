#include "Team.hpp"

using namespace std;
namespace ariel {
    Team::Team(Character *leader) : _leader(leader), _members(0), current_members(1) {
        add(leader);
    }

    void Team::add(Character *member) {
        if (current_members < 10) {
            current_members++;
            _members.push_back(member);
        } else throw std::out_of_range("Too many members in the team.");
    }

    void Team::attack(Team *enemies) {

    }

    int Team::stillAlive() const {
        int count = 0;
        for (Character *member: _members) {
            if (member not_eq nullptr && member->isAlive()) {
                count++;
            }
        }
        return count;
    }

    std::string Team::print() const {
        std::string str;
        for (Character *member: _members) {
            str += member->print();
        }
        cout << str;
    }

}