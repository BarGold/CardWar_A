#include <stdexcept>
using namespace std;

namespace ariel
{

    class Player
    {
    private:
        string name;

    public:
        Player(string name);

        void getName();
        
        // function of player
        int stacksize();
        int cardesTaken();

    };

}
