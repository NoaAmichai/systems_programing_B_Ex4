#include "Ninja.hpp"

using namespace std;
namespace ariel {

    void Ninja::move(const Character *enemy) {
        if (!isAlive()) {
            throw runtime_error(getName() + " can't move.");
        }
        const Point &enemy_location = enemy->getLocation();
        const Point &current_location = getLocation();

        double distance = current_location.distance(enemy_location);
        double max_distance = _speed;

        if (distance <= max_distance) {
            setLocation(enemy_location);
        } else {
            Point new_location = Point::moveTowards(current_location, enemy_location, max_distance);
            setLocation(new_location);
        }
    }

    void Ninja::slash(Character *enemy) {
        if (!isAlive() || !enemy->isAlive()) throw runtime_error("The attacker or the enemy is not alive");
        if (this == enemy) throw std::runtime_error("Ninja can't slash himself");
        Point enemy_location = enemy->getLocation();
        Point current_location = getLocation();
        double distance = current_location.distance(enemy_location);
        if (distance <= 1) {
            enemy->hit(40);
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
