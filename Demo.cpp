/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <random>
#include <chrono>
#include <iostream>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


//double random_float(double min = -100, double max = 100) {
//    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
//    std::uniform_real_distribution<double> distribution(min, max);
//
//    return distribution(generator);
//};

int main() {

//    auto create_yninja = [](double x = random_float(), double y = random_float()) {
//        return new YoungNinja{"Bob", Point{x, y}};
//    };
//
//    auto create_tninja = [](double x = random_float(), double y = random_float()) {
//        return new TrainedNinja{"Bob", Point{x, y}};
//    };
//
//    auto create_oninja = [](double x = random_float(), double y = random_float()) {
//        return new OldNinja{"Bob", Point{x, y}};
//    };
//
//    auto create_cowboy = [](double x = random_float(), double y = random_float()) {
//        return new Cowboy{"Bob", Point{x, y}};
//    };
//
//    auto cowboy = create_cowboy(1,2);
//    auto cowboy1 = create_cowboy(3,4);
//    auto cowboy2 = create_cowboy(5,6);
//    auto cowboy3 = create_cowboy(7,8);
//    auto cowboy4 = create_cowboy(9,10);
//    auto ninja = create_oninja(1,2);
//    auto ninja1 = create_oninja(3,4);
//    auto ninja2 = create_oninja(5,6);
//    auto ninja3 = create_oninja(7,8);
//    auto ninja4 = create_oninja(9,10);
//    Team team(cowboy);
//    team.add(ninja);
//    team.add(ninja1);
//    team.add(cowboy1);
//    team.add(ninja2);
//    team.add(cowboy2);
//    team.add(ninja3);
//    team.add(ninja4);
//    team.add(cowboy3);
//    team.add(cowboy4);
//    team.print();



    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom);
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team b(tom); should throw tom is already in team a

    Team team_B(sushi);
    team_B.add(new TrainedNinja("Hikari", Point(12,81)));


    while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
    }

    if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
    else cout << "winner is team_B" << endl;

    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}