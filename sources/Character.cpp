#include "Character.hpp"

using namespace std;
namespace ariel {

    bool Character::isAlive() const {
        return _hit_points > 0;
    }

    double Character::distance(const Character &other) const {
        return sqrt(
                pow(_location.getX() - other._location.getX(), 2) + pow(_location.getY() - other._location.getY(), 2));
    }

    void Character::hit(int points) {
        _hit_points -= points;
        if (_hit_points < 0) {
            _hit_points = 0;
        }
    }

    string Character::getName() const {
        return _name;
    }

    const Point &Character::getLocation() const {
        return _location;
    }

    string Character::print() const {
        string str;
        if (!isAlive()) {
            str += "Name: (" + _name + "), Location:" +
                   _location.print()
                   + '\n';
        } else {
            str += "Name: " + _name + ", Hit Points:" + " (" + to_string(_hit_points) + ") " + ", Location: " +
                   _location.print() + '\n';
        }
        return str;

    }


}