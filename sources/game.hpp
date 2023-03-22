#include <string>
#include <stdexcept>
#include "player.hpp"
using namespace std;

namespace ariel
{

    class Game
    {
    private:
        ariel::Player p1;
        ariel::Player p2;

        double draw_rate;
        int draw_amount; //  (draw within a draw counts as 2 draws. ) 

        int war; // count how many war have in 1 turn;
        // draw rate

    public:
        Game();
        Game(ariel::Player p1, ariel::Player p2); 
        

        void playTurn(); // play turn
        void printLastTurn(); // print the last turn stats.

        void playAll(); //playes the game untill the end
        void printWiner(); // prints the name of the winning player
        void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
        void printStats(); // for each player prints basic statistics: win rate, cards won,
                         // <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    };
}
