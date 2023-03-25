#include <iostream>
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
Player p7("Aviv");
Player p8("Or");

Player p5("Niv"); // player that create but not play any Game

// Create games with 4 players
Game game(p1,p2);
Game game1(p3,p4);
Game game3(p7,p8);


TEST_CASE("Game"){

    // test for stacksize()
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0); // new game
    CHECK(p2.cardesTaken() == 0); // new game
    CHECK(p5.stacksize() == 0);

    game.playTurn(); 
    
    if(p2.cardesTaken() >= 2){ // player p2 is win 
       CHECK(p1.cardesTaken() == 0);
    }
    else{ // player p2 is loss
        CHECK(p2.cardesTaken() == 0);
    }
    game.playTurn();
    CHECK(p1.stacksize() <= 24);
    CHECK(p2.stacksize() <= 24);
    game.playTurn();
    game.playTurn();
    game.playTurn();
    game.playTurn();
    game.playTurn();
    game.playTurn();

}

TEST_CASE("Game 1"){
    // test for stacksize()
    CHECK(p3.stacksize() == 26);
    CHECK(p4.stacksize() == 26);
    CHECK(p3.cardesTaken() == 0); // new game
    CHECK(p4.cardesTaken() == 0); // new game

    CHECK(p5.stacksize() == 0); // stay amount of cards left = 0 dont play
    CHECK(p5.cardesTaken() == 0);

    if(p3.cardesTaken() >= 2){ // player p3 is win 
       CHECK(p4.cardesTaken() == 0);
    }
    else{ // player p3 is loss
        CHECK(p3.cardesTaken() == 0);
    }
    game1.playTurn();
    CHECK(p3.stacksize() <= 24);
    CHECK(p4.stacksize() <= 24);
}


TEST_CASE("Game 3")
{
    game3.playTurn();
    CHECK(p7.cardesTaken() != p8.cardesTaken()); // one of them need to win 
    CHECK(p5.stacksize() != 26); // p5 dont play a game
    game3.playTurn();
    game3.playTurn();
    game3.playTurn();
    game3.playTurn();
    game3.playTurn();
    game3.playTurn();
    game3.playTurn();
    if(p7.cardesTaken() != p8.cardesTaken()){
        if(p7.cardesTaken() > p8.cardesTaken()){
            CHECK(p7.cardesTaken() > p8.cardesTaken());
        }
        else{
            CHECK(p7.cardesTaken() < p8.cardesTaken());
        }
    }
}