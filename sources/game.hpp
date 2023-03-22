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

        string name_win;

        double draw_rate;
        int draw_amount; //  (draw within a draw counts as 2 draws. )

        int war; // count how many war have in 1 turn;
        // draw rate

    public:
        Game(ariel::Player p1, ariel::Player p2);

        void set_war();
        int get_war();

        void set_name_win();
        string get_name_win();

        //        void set_name_win();
        void playTurn();      // play turn
        void printLastTurn(); // print the last turn stats.

        void playAll();    // playes the game untill the end
        void printWiner(); // prints the name of the winning player
        void printLog();   // prints all the turns played one line per turn (same format as game.printLastTurn())
        void printStats(); // for each player prints basic statistics: win rate, cards won,
                           // <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    };
}
