#include "sources/Team.hpp"

#include "doctest.h"

using namespace ariel;

TEST_CASE("Point class tests") {

    SUBCASE("getX and getY Test") {
        Point p;
        CHECK(p.getX() == 0.0);
        CHECK(p.getY() == 0.0);

        Point c(0.0, 0.0);
        Point d(0.0, 0.0);
        CHECK_EQ(c.getY(), d.getY());
        CHECK_EQ(c.getX(), d.getX());

        CHECK_NOTHROW(Point::moveTowards(c, d, 500));
    }

    SUBCASE("distance function Test") {
        Point p1(2.0, 3.0);
        Point p2(2.0, 3.0);
        CHECK_EQ(p1.distance(p2), 0.0);
        CHECK_EQ(p1.distance(p2), p2.distance(p1));
    }

    SUBCASE("Print Test") {
        Point a(1.0, 2.0);
        CHECK(a.print() == "(1,2)");
    }

    SUBCASE("Move Towards Test") {
        Point source(1.0, 1.0);
        Point dest(4.0, 5.0);
        double max_distance = 5.0;
        Point result = Point::moveTowards(source, dest, max_distance);
        CHECK(result.getX() == dest.getX());
        CHECK(result.getY() == dest.getY());
    }

    SUBCASE("moveTowards function should throw an invalid_argument exception if max_distance is negative") {
        Point source(1.0, 1.0);
        Point dest(4.0, 5.0);
        double max_distance = -1.0;
        CHECK_THROWS(Point::moveTowards(source, dest, max_distance));
    }
}

TEST_CASE("Ninja class tests") {
    SUBCASE("Ninja's move function") {
        Point p1(0, 0), p2(0, 2), p3(0, -1), p4(0, 5);
        YoungNinja *young_ninja = new YoungNinja("YoungNinja", p1);
        Cowboy *cowboy = new Cowboy("Enemy", p4);
        young_ninja->move(cowboy);
        CHECK(young_ninja->getLocation().getY() == p2.getY());
        CHECK(young_ninja->getLocation().getY() == p2.getY());
    }

    SUBCASE("Ninja's slash function") {
        Point p1(0, 0);
        YoungNinja *young_ninja = new YoungNinja("YoungNinja", p1);
        Cowboy *cowboy = new Cowboy("cowboy", p1);

        CHECK(cowboy->isAlive());
        CHECK(young_ninja->isAlive());
        while (cowboy->isAlive()) {
            CHECK_NOTHROW(young_ninja->slash(cowboy));
        }
        CHECK_THROWS(young_ninja->slash(cowboy));
    }
}

TEST_SUITE("Team class") {
    Point p1(0, 0), p2(0, 2), p3(0, -1), p4(0, 15);
    OldNinja *oldNinja = new OldNinja("oldNinja", p1);
    YoungNinja *youngNinja = new YoungNinja("youngNinja", p2);
    TrainedNinja *trainedNinja = new TrainedNinja("trainedNinja", p3);
    Cowboy *cowboy = new Cowboy("cowboy", p4);

    TEST_CASE("Creating a team with a leader") {
        Team team(oldNinja);
        CHECK(team.stillAlive() == 1);
    }
}

TEST_SUITE("Point class tests") {
    Point p1{1, 1};
    Point p2{2, 3};
    Point n1{-1, 1};
    Point n2{1, -9};
    Point n3{-1, -1};

    TEST_CASE("Distance method") {
        CHECK(p1.distance(p2) == p2.distance(p1));
        CHECK(n1.distance(n2) == n2.distance(n1));
        CHECK(n3.distance(p1) == p1.distance(n3));

        CHECK(n2.distance(p1) == 10);
        CHECK(p2.distance(n3) == 5);
        CHECK(p1.distance(p1) == 0);
    }

    TEST_CASE("moveTowards method") {
        double distance = p1.distance(p2);
        double half_p = distance / 2;
        double third_p = distance / 3;

        Point p3 = Point::moveTowards(p1, p2, half_p);
        CHECK(p3.distance(p2) == doctest::Approx(half_p).epsilon(0.001));

        Point p4 = Point::moveTowards(p1, p2, third_p);
        CHECK(p4.distance(p2) == doctest::Approx(third_p * 2).epsilon(0.001));

        CHECK_THROWS_AS(Point::moveTowards(p1, p2, -1), std::invalid_argument);
    }
}
