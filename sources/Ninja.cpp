#include "Ninja.hpp"

using namespace std;
namespace ariel {

    void Ninja::move(const Character *enemy) {
        if (!isAlive()) {
            throw runtime_error(getName() + " can't move.");
        }
        Point enemy_location = enemy->getLocation();
        Point current_location = getLocation();

        double distance = current_location.distance(enemy_location);
        if (distance <= _speed) {
            setLocation(enemy_location);
        } else {
            setLocation(Point::moveTowards(current_location, enemy_location, distance * _speed)); //TODO Check!
        }

    }

    void Ninja::slash(Character *enemy) {
        if (enemy->isAlive()) {
            Point enemy_location = enemy->getLocation();
            Point current_location = getLocation();
            double distance = current_location.distance(enemy_location);
            if (distance <= 1) {
                enemy->hit(31);
            }

        }
    }

    string Ninja::print() const {
        return "N : " + Character::print();
    }

}