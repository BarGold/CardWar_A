#include <stdexcept>
using namespace std;

namespace ariel
{

    class Player
    {
    private:
        string name;
        int stack_size;  //amount of cards left
        int cardes_Taken; //amount of cards this player has won. 
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
