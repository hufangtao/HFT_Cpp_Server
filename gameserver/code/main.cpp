#include <iostream>
#include <map>
#include "player.h"
#include "timer.h"
using namespace std;

int main()
{
    boost::asio::io_context io;
    Timer timer(io);
    io.run();
    return 0;
}

