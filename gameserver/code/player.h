#include <string>

class Player
{
    public:
        Player(): level(0), exp(0) {}
        ~Player() {}

        int getLevel();
        int getExp();

    private:
        std::string name;
        int level;
        int exp;
};
