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

Player p5("Niv"); // player that create but not play any Game

// Create games with 4 players
Game game(p1,p2);
Game game1(p3,p4);
Game game2(p1,p4);
Game game3(p2,p4);


TEST_CASE("Good Game"){

    // test for stacksize()
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p5.stacksize() == 0);
    game.playTurn();
    if(game.get_Wins_Name() == "Bob"){ // player p2 is win 
       CHECK(p2.cardesTaken() >= 1);
    }
    else{ // player p2 is loss
        CHECK(p1.cardesTaken() >= 1);
    }
    game.playTurn();
    CHECK(p3.stacksize() <= 24);
    CHECK(p4.stacksize() <= 24);
    CHECK(p3.getName() == "Bar");
    CHECK(p4.getName() == "Gal");
    CHECK(p2.getName() == "Bob");
    CHECK(p1.getName() == "Alice");


        // test for stacksize()
    CHECK(p3.stacksize() == 26);
    CHECK(p4.stacksize() == 26);
    game.playTurn();
    if(game.get_Wins_Name() == "Bar"){ // player p3 is win 
       CHECK(p3.cardesTaken() >= 1);
    }
    else{ // player p3 is loss
        CHECK(p4.cardesTaken() >= 1);
    }
    game.playTurn();
    CHECK(p3.stacksize() <= 24);
    CHECK(p4.stacksize() <= 24);
    CHECK(p2.getName() == "Bob");
    CHECK(p1.getName() == "Alice");

    


}

TEST_CASE("Bad Game")
{
    
}