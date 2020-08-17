#include "timer.h"
#include "sync_tcp_client.h"

int main()
{
    asio::io_context io;
	SyncTcpClient client(io, "localhost", "22001");
	client.connect();
    io.run();
	client.syncRead();
    return 0;
}

