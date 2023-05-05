#include "sources/Team.hpp"

#include "doctest.h"

using namespace ariel;

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


TEST_CASE("Adding characters to team") {
    Point p1(1, 2), p2(3, 4), p3(5, 6);
    Cowboy c1("cowboy1", p1);
    OldNinja n1("ninja1", p2);
    TrainedNinja n2("ninja2", p3);
    Team team(&c1);
    CHECK(team.stillAlive() == 1);

    SUBCASE("Adding same character twice should throw exception") {
        CHECK_THROWS_AS(team.add(&c1), std::invalid_argument);
        CHECK(team.stillAlive() == 1);
    }

    SUBCASE("Adding characters to the team") {
        team.add(&n1);
        CHECK(team.stillAlive() == 2);
        team.add(&n2);
        CHECK(team.stillAlive() == 3);
    }
}

TEST_CASE("Attacking enemy team") {
    Point p1(1, 2), p2(3, 4), p3(5, 6), p4(7, 8);
    Cowboy c1("cowboy1", p1), c2("cowboy2", p2);
    OldNinja n1("ninja1", p3), n2("ninja2", p4);
    Team team_a(&c1), team_b(&n1);

    SUBCASE("Attacking with no living members should end attack") {
        team_a.attack(&team_b);
        CHECK(team_b.stillAlive() == 1);
    }

    SUBCASE("Attacking with living members") {
        team_a.add(&c2);
        team_b.add(&n2);
        while (team_a.stillAlive() > 0 && team_b.stillAlive() > 0) {
            team_a.attack(&team_b);
            team_b.attack(&team_a);
        }
        CHECK((team_a.stillAlive() == 0 || team_b.stillAlive() == 0));
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



