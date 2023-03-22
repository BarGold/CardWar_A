#include <iostream>
#include <stdexcept>
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <fstream>
#include <sstream>
#include "card.hpp"
using namespace std;

namespace ariel
{

    class Player
    {

    private:
        string name;
        int stack_size;   // amount of cards left
        int cardes_Taken; // amount of cards this player has won.

        double win_rate;

        bool win; // if he win 1 , loss 0
        ariel::Card card_Play; // player card for turn
        // cards won;

    public:
        Player(string name);

        string getName();

        int stacksize();
        void set_stacksize();
        
        int cardesTaken();
        void set_cardesTaken();

        void set_win_rate();
        double get_win_rate();

        void set_win();
        bool get_win();

    };

}
#endif