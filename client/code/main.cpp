#include "timer.h"
#include "sync_tcp_client.h"

int main()
{
	asio::io_context io;
	SyncTcpClient client(io, "127.0.0.1", "9999");
	client.connect();
	client.syncRead();
	io.run();
	return 0;
}

