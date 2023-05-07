#pragma once

#include <iostream>
#include <cmath>

namespace ariel {

    class Point {
    private:
        double coord_x, coord_y;

    public:
        Point(double coord_x = 0.0, double coord_y = 0.0) : coord_x(coord_x), coord_y(coord_y) {}

        double getX() const;

        double getY() const;

        double distance(const Point &other) const;

        std::string print() const;

        static Point moveTowards(const Point &source, const Point &dest, double max_distance);
    };

}
