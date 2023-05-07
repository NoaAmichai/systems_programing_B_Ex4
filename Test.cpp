#include "sources/Team.hpp"

#include "doctest.h"

using namespace ariel;


TEST_CASE("Point class tests") {

    SUBCASE("getX and getY functions should return 0.0 for newly created points") {
        Point p;
        CHECK(p.getX() == 0.0);
        CHECK(p.getY() == 0.0);
    }

    SUBCASE("distance function should return 0.0 for points that are the same") {
        Point p1(2.0, 3.0);
        Point p2(2.0, 3.0);
        CHECK(p1.distance(p2) == 0.0);
    }

    SUBCASE("print function should return the expected string representation") {
        Point p(2.5, 3.8);
        CHECK(p.print() == "(2.5, 3.8)");
    }

    SUBCASE("moveTowards function should return the destination point if max_distance is greater than or equal to the distance between source and dest") {
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
        CHECK_THROWS_AS(Point::moveTowards(source, dest, max_distance), std::invalid_argument);
    }

    SUBCASE("moveTowards function should return a point that is max_distance away from source if dest is far away") {
        Point source(1.0, 1.0);
        Point dest(4.0, 5.0);
        double max_distance = 3.0;
        Point result = ariel::Point::moveTowards(source, dest, max_distance);
        double actual_distance = source.distance(result);
        CHECK(actual_distance == doctest::Approx(max_distance));
    }
}

TEST_CASE("Test team functionality") {
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    Team team_A(tom);
    Team team_B(sushi);

    SUBCASE("Test adding new members") {
        team_A.add(new YoungNinja("Yogi", Point(64, 57)));
        team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

        CHECK(team_A.stillAlive() == 2);
        CHECK(team_B.stillAlive() == 2);
    }

    SUBCASE("Test attacking") {
        team_A.attack(&team_B);

        CHECK(team_A.stillAlive() == 2);
        CHECK(team_B.stillAlive() == 1);
    }
}

TEST_CASE("Distance Test") {
    Point a(2.0, 3.0);
    Point b(4.0, 1.0);
    CHECK(a.distance(b) == b.distance(a));
    CHECK(a.distance(b) == doctest::Approx(2.8284).epsilon(0.0001));
}

TEST_CASE("Print Test") {
    Point a(1.0, 2.0);
    CHECK(a.print() == "(1,2)");
}

TEST_CASE("Move Towards Test") {
    Point a(1.0, 2.0);
    Point b(4.0, 6.0);
    Point c(0.0, 0.0);
    a.moveTowards(c, b, 2.0);
    CHECK(a.distance(b) == doctest::Approx(2.0).epsilon(0.0001));
    CHECK(a.print() == "(1.60078,3.20078)");
}

TEST_SUITE("Ninja sub-classes functions") {
    Point p1(0, 0), p2(0, 2), p3(0, -1), p4(0, 15);
    OldNinja *oldNinja = new OldNinja("oldNinja", p1);
    YoungNinja *youngNinja = new YoungNinja("youngNinja", p2);
    TrainedNinja *trainedNinja = new TrainedNinja("trainedNinja", p3);
    Cowboy *enemy = new Cowboy("enemy", p4);

    TEST_CASE("Hit and isAlive functions") {
        oldNinja->hit(100);
        CHECK((oldNinja->isAlive() == true));
        oldNinja->hit(50);
        CHECK((oldNinja->isAlive() == false));

        youngNinja->hit(100);
        CHECK((youngNinja->isAlive() == true));
        youngNinja->hit(20);
        CHECK((youngNinja->isAlive() == false));

        trainedNinja->hit(80);
        CHECK((trainedNinja->isAlive() == true));
        trainedNinja->hit(20);
        CHECK((trainedNinja->isAlive() == false));
    }
}