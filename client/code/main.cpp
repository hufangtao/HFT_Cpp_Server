#include "timer.h"
#include "sync_tcp_client.h"

int main()
{
    asio::io_context io;

    io.run();
    return 0;
}

