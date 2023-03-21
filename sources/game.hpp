#include <string>
using namespace std;
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

        string get_Wins_Name(); // get the name of winnwr in game
        string get_Shape_Card(); // get the shape of card (to the printLastTurn()) 

        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void printLastTurn();
        void playTurn();
    };

}
