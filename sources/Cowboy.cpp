
#include "Cowboy.hpp"

using namespace std;
namespace ariel {

    void Cowboy::shoot(Character *enemy) {
        if (isAlive() && _bullets > 0) {
            --_bullets;
            enemy->hit(10);
        }
    }

    bool Cowboy::hasBullets() const {
        return _bullets > 0;
    }

    void Cowboy::reload() {
        _bullets += 6;
    }

    void Cowboy::print() const {
        cout << "C : " << endl;
        Character::print();
    }
}