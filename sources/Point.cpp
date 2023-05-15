
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {

    Point::Point(double coord_x, double coord_y) : coord_x(coord_x), coord_y(coord_y) {}

    double Point::getX() const {
        return coord_x;
    }

    double Point::getY() const {
        return coord_y;
    }

    double Point::distance(const Point &other) const {
        return sqrt(pow(coord_x - other.coord_x, 2) + pow(coord_y - other.coord_y, 2));
    }

    string Point::print() const {
        string str = "(" + to_string(coord_x) + ", " + to_string(coord_y) + ")";
        return str;
    }

    Point Point::moveTowards(const Point &source, const Point &dest, double max_distance) {
        if (max_distance < 0) {
            throw invalid_argument("distance must be non-negative");
        }
        double distance = source.distance(dest);
        if (distance <= max_distance) return dest;

        double ratio = max_distance / distance;
        double dx = dest.coord_x - source.coord_x;
        double dy = dest.coord_y - source.coord_y;
        return {source.coord_x + dx * ratio, source.coord_y + dy * ratio};
    }

}