#include <iostream>
#include <stdexcept>
using namespace std;

#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;


// Create players with their names
Player p1("Alice");
Player p2("Bob");
Player p3("Bar");
Player p4("Gal");
// player that create but not play any Game
Player p5("Niv"); 

Player p7("Aviv");
Player p8("Or");


// Create games
Game game(p1,p2);
Game game1(p3,p4);
Game game3(p7,p8);


TEST_CASE("Game - SIMPEL TEST"){

    // test for stacksize() && cardesTaken() for new game
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0); 
    CHECK(p2.cardesTaken() == 0); 

    // player that create but not play any Game 
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

}

TEST_CASE("Game 1 - CHECK_NOTHROW "){
    // test for stacksize() && cardesTaken() for new game
    CHECK(p3.stacksize() == 26);
    CHECK(p4.stacksize() == 26);
    CHECK(p3.cardesTaken() == 0);
    CHECK(p4.cardesTaken() == 0); 

    // player that create but not play any Game 
    CHECK(p5.stacksize() == 0); 
    CHECK(p5.cardesTaken() == 0);

    game1.playTurn();
    CHECK_NOTHROW(game1.playAll());
    CHECK_NOTHROW(game1.printLog());
    CHECK_NOTHROW(game1.printStats());
    CHECK_NOTHROW(game1.printLastTurn());

    if(p3.cardesTaken() >= 2){ // player p3 is win 
       CHECK(p4.cardesTaken() == 0);
    }
    else{ // player p3 is loss
        CHECK(p3.cardesTaken() == 0);
    }

    game1.playTurn();
    CHECK_NOTHROW(game1.printLastTurn());
    CHECK(p3.stacksize() <= 24);
    CHECK(p4.stacksize() <= 24);
    for (int i=0;i<6;i++)
    {
        game1.playTurn();   
    }
    CHECK_NOTHROW(game1.playAll());
    CHECK_NOTHROW(game1.printLog());
    CHECK_NOTHROW(game1.printStats());
    CHECK_NOTHROW(game1.playTurn());
    game1.playTurn();
    CHECK_NOTHROW(game1.printLastTurn());
}


TEST_CASE("Game 3")
{
    game3.playTurn();
    CHECK(p7.cardesTaken() != p8.cardesTaken()); // one of them need to win 
    CHECK(p5.stacksize() != 26); // p5 dont play a game
    for (int i=0;i<6;i++)
    {
        game3.playTurn();   
    }
    CHECK(p7.stacksize() == p8.stacksize());
    if(p7.cardesTaken() != p8.cardesTaken()){
        if(p7.cardesTaken() > p8.cardesTaken()){
            CHECK(p7.cardesTaken() > p8.cardesTaken());
        }
        else{
            CHECK(p7.cardesTaken() < p8.cardesTaken());
        }
    }
}