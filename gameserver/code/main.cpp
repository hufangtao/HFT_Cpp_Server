#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/timer.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/make_unique.hpp>
#include "player.h"
using namespace boost;
using namespace std;

int main()
{
    timer t;
    int a = lexical_cast<int>("12");
    cout << a << endl;
    cout << "Hello World" << endl;
    try
    {
        int err = lexical_cast<int>("789edc", 4);
        cout << err << endl;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }

    auto up = boost::make_unique<int>(20);
    auto up1 = up;
    cout << "up:" << *up << "_" << *up1 << endl;

    Player player;
    cout << "player level :" << player.getLevel() << endl;
    return 0;
}
