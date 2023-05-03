#pragma once

#include "Character.hpp"

namespace ariel {

    class Cowboy :public Character{
    private:


    public:
        Cowboy(std::string name, Point point): Character(name, point){};
    };
}


