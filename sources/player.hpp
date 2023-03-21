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

        string getName();
        
        int stacksize();
        int cardesTaken();

    };

}
