#include <stdexcept>
using namespace std;

namespace ariel
{

    class Player
    {
    private:
        string name;
        int stacksize;  //amount of cards left
        int cardesTaken; //amount of cards this player has won. 
        double win_rate;
        //cards won;

    public:
        Player(string name);

        string getName();
        double get_win_rate();
        double set_win_rate();

        int stacksize();
        int cardesTaken();

    };

}
