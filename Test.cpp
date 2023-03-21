#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;


// Create 4 players with their names
Player p1("Alice");
Player p2("Bob");
Player p3("Bar");
Player p4("Gal");

// Create games with 4 players
Game game(p1,p2);
Game game1(p3,p4);
Game game2(p1,p4);
Game game3(p2,p4);


TEST_CASE("Good Game"){

}

TEST_CASE("Bad Game")
{
    CHECK_THROWS(); // 
}