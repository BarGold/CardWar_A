#include <string>
#include <stdexcept>
using namespace std;

namespace ariel{

    class Card
    {
    private:
        int num;
        string shape; //Spades , Hearts , Clubs , Diamonds
    public:
        int get_num();
        string get_shapr();
    
    };
  
}