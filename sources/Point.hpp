#pragma once
namespace ariel {

    class Point {
    private:
        double _x, _y;

    public:
        Point(double x, double y) : _x(x), _y(y) {}

        double distance(const Point &other) const;

        void print() const;

        Point moveTowards(const Point &dest, double distance) const;

    };

}
