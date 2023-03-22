#include <string>
#include <stdexcept>
#include "player.hpp"
#ifndef PLAYER_H
using namespace std;
using  ariel::Player;

namespace ariel
{

    class Game
    {
    private:
        Player winner;
        double draw_rate;
        int draw_amount; //  (draw within a draw counts as 2 draws. ) 

    public:
        Game(Player p1, Player p2); 
        
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void printLastTurn();
        void playTurn();
    };
    #endif

}
