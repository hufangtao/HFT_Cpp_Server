#include "player.h"
#include "tcp_server.h"

int main()
{
    asio::io_context io;
	TcpServer server(io);
    io.run();
    return 0;
}

