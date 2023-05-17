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

    TEST_CASE("Adding members to the team") {
        Team team(oldNinja);
        CHECK_NOTHROW(team.add(youngNinja));
        CHECK_NOTHROW(team.add(trainedNinja));
        CHECK_NOTHROW(team.add(cowboy));
        CHECK(team.stillAlive() == 4);
    }

    TEST_CASE("Attacking other teams") {
        Team team(oldNinja);
        Team enemies(cowboy);
        CHECK_NOTHROW(team.attack(&enemies));
        CHECK(enemies.stillAlive() == 0);
    }

    TEST_CASE("Printing the team's members") {
        Team team(oldNinja);
        team.add(youngNinja);
        team.add(trainedNinja);
        team.add(cowboy);
        CHECK_NOTHROW(team.print());
    }
}
