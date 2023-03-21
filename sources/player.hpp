#include <stdexcept>
using namespace std;

namespace ariel
{

    class Player
    {
    private:
        string name;
        int stacksize;  //  amount of cards left
        int cardesTaken; //amount of cards this player has won. 

    public:
        Player(string name);

        string getName();
        
        int stacksize();
        int cardesTaken();

    };

}
