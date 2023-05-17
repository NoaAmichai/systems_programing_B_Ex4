#include "Character.hpp"

using namespace std;
namespace ariel {

    bool Character::isAlive() const {
        return _hit_points > 0;
    }

    double Character::distance(const Character *other) const {
        return sqrt(pow(_location.getX() - other->_location.getX(), 2) +
                    pow(_location.getY() - other->_location.getY(), 2));
    }

    void Character::hit(int points) {
        if (points < 0) throw std::invalid_argument("Hit can't get negative value");
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

    void Character::setLocation(const Point &location) {
        _location = location;
    }

    int Character::getHitPoints() const {
        return _hit_points;
    }

    bool Character::isInGame() const {
        return _in_game;
    }

    void Character::setInGame(bool inGame) {
        _in_game = inGame;
    }

}