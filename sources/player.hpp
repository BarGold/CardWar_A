#include <iostream>
#include <stdexcept>
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <fstream>
#include <sstream>
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
        // cards won;

    public:
        Player();
        Player(string name);
        double set_win_rate();

        int stacksize();
        int cardesTaken();
    };

}
#endif