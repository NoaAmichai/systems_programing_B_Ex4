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
        if (isAlive()) {
            Point enemy_location = enemy->getLocation();
            Point current_location = getLocation();
            double distance = current_location.distance(enemy_location);
            if (distance <= 1) {
                enemy->hit(40);
            }

        }
    }

    string Ninja::print() const {
        string str = "N : ";
        if (!isAlive()) {
            str += "Name: (" + getName() + "), Location:" +
                   getLocation().print()
                   + '\n';
        } else {
            str += "Name: " + getName() + ", Hit Points:" + " (" + to_string(getHitPoints()) + ") " + ", Location: " +
                   getLocation().print() + '\n';
        }
        return str;
    }
}
