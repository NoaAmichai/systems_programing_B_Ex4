#pragma once

#include <iostream>
#include <cmath>

namespace ariel {

    class Point {
    public:
        double getX() const;

        double getY() const;

    private:
        double _x, _y;

    public:
        Point(double x = 0.0, double y = 0.0) : _x(x), _y(y) {}

        double distance(const Point &other) const;

        std::string print() const;

        Point moveTowards(const Point &source, const Point &dest, const double max_distance) const;
    };

}
