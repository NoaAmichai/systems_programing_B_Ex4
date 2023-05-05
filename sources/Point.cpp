
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {

    double Point::getX() const {
        return _x;
    }

    double Point::getY() const {
        return _y;
    }

    double Point::distance(const Point &other) const {
        return sqrt(pow(_x - other._x, 2) + pow(_y - other._y, 2));
    }

    void Point::print() const {
        std::cout << "(" << _x << ", " << _y << ")";
    }

    Point Point::moveTowards(const Point &source, const Point &dest, const double max_distance) const {
        if (max_distance < 0) {
            throw invalid_argument("distance must be non-negative");
        }
        double distance = source.distance(dest);
        if (distance <= max_distance) return dest;

        double ratio = max_distance / distance;
        double dx = dest._x - source._x;
        double dy = dest._y - source._y;
        return Point(source._x + dx * ratio, source._y + dy * ratio);


    }

}