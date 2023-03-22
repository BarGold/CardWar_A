#include <string>
#include <stdexcept>
#include "player.hpp"
using namespace std;

namespace ariel
{

    class Game
    {
    private:
        ariel::Player winner;
        double draw_rate;
        int draw_amount; //  (draw within a draw counts as 2 draws. ) 

    public:
        Game();
        Game(ariel::Player p1, ariel::Player p2); 
        

        void playTurn(); // play turn
        void printLastTurn();

        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}
