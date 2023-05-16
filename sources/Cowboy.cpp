
#include "Cowboy.hpp"

using namespace std;
namespace ariel {

    void Cowboy::shoot(Character *enemy) {
        if (isAlive() && _bullets > 0) {
            --_bullets;
            enemy->hit(10);
        }
    }

    bool Cowboy::hasboolets() const {
        return _bullets > 0;
    }

    void Cowboy::reload() {
        if (_bullets == 0) {
            _bullets += 6;
        }
    }

    string Cowboy::print() const {
        string str = "C : ";
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
