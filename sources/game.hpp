#include <string>
using namespace std;
namespace ariel
{

    class Game
    {
        Player winner;

    public:
        Game(Player p1, Player p2);
        string get_Wins_Name();

        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void printLastTurn();
        void playTurn();
    };

}
