#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/timer.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/make_unique.hpp>
#include "player.h"
using namespace boost;
using namespace std;

void testPlayer(Player* player)
{
    boost::shared_ptr<Player> p1(player);
}

int main()
{
    Player* player_ = new Player();
    testPlayer(player_);

    // cout << "p1:" << p1.use_count() << "p2:" << player_->use_count();
    cout << "p2:" << player_->getLevel();

    int a;
    cout << "pls cin a" << endl;
    cin >> a;

    switch (a)
    {
        case 1:
        {
            cout << "is a 1" << endl;
            break;
        }
        case 2:
        {
            cout << "is a 2" << endl;
            break;
        }
    }

    cout << "the end" << endl;

    return 0;
}
