#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <string>
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

        int win; // if he win 1 , loss 0
        ariel::Card card_Play; // player card for turn
        // cards won;

    public:
        Player();
        Player(string name);

        string getName();

        int stacksize();
        void set_stacksize();
        
        int cardesTaken();
        void set_cardesTaken();

        void set_win_rate();
        double get_win_rate();

        void set_win();
        int get_win();

    };

}
#endif