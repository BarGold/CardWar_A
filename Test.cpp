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
    CHECK(p1.cardesTaken() == 0); // new game
    CHECK(p2.cardesTaken() == 0); // new game
    CHECK(p5.stacksize() == 0);

    game.playTurn(); 
    
    if(p2.get_win() == 1){ // player p2 is win 
       CHECK(p2.cardesTaken() >= 2);
    }
    else{ // player p2 is loss
        CHECK(p1.cardesTaken() >= 2);
    }
    game.playTurn();
    CHECK(p3.stacksize() <= 24);
    CHECK(p4.stacksize() <= 24);
    CHECK(p3.getName() == "Bar");
    CHECK(p4.getName() == "Gal");
    CHECK(p2.getName() == "Bob");
    CHECK(p1.getName() == "Alice");
    game.playTurn();
    game.playTurn();
    game.playTurn();
    game.playTurn();
    game.playTurn();
    game.playTurn();
    if(p2.cardesTaken() > p1.cardesTaken()){
        CHECK(p2.get_win_rate() > p1.get_win_rate());
    }
    else{
         CHECK(p2.get_win_rate() < p1.get_win_rate());
    }

    // test for stacksize()
    CHECK(p3.stacksize() == 26);
    CHECK(p4.stacksize() == 26);
    CHECK(p3.cardesTaken() == 0); // new game
    CHECK(p4.cardesTaken() == 0); // new game

    CHECK(p5.stacksize() == 0); // stay amount of cards left = 0 dont play
    CHECK(p5.cardesTaken() == 0);

    game1.playTurn();
    if (p3.get_win() == 1 && game1.get_war() == 0) // no war in this turn
    {                                              // player p3 is win
        CHECK(p3.cardesTaken() == 2);
        CHECK(p4.cardesTaken() == 0);
    }
    if (p4.get_win() == 1 && game1.get_war() == 0)
    {
        CHECK(p4.cardesTaken() == 2);
        CHECK(p3.cardesTaken() == 0);
    }
    else
    { // was a war
        if (p3.get_win() == 1)
        {
            CHECK(p4.cardesTaken() == 0);
        }
        if (p4.get_win() == 1)
        {
            CHECK(p3.cardesTaken() == 0);
        }
    }
    game1.playTurn();
    CHECK(p3.stacksize() <= 24);
    CHECK(p4.stacksize() <= 24);
    CHECK(p2.getName() == "Bob");
    CHECK(p1.getName() == "Alice");

    


}


TEST_CASE("Bad Game")
{
    game3.playTurn();
    CHECK(p2.cardesTaken() != p4.cardesTaken()); // one of them need to win 
    CHECK(p2.getName() != "Bar");
    CHECK(p5.stacksize() != 26); // p5 dont play a game
    game3.playTurn();
    CHECK(game3.get_name_win() != "Bar"); // bar dont play in game 3
    game3.playTurn();
    game3.playTurn();
    game3.playTurn();
    game3.playTurn();
    game3.playTurn();
    game3.playTurn();
    if(p2.cardesTaken() != p4.cardesTaken()){
        CHECK(p2.get_win_rate() != p4.get_win_rate());
    }
}