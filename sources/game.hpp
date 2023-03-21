#include <string>
using namespace std;
namespace ariel
{

    class Game
    {
    

    public:
        Game(Player p1, Player p2);

        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void printLastTurn();
        void playTurn();
    };

}
