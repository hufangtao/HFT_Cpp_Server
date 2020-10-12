#include "timer.h"
#include "hnet/asio_client/sync_tcp_client.h"

int main()
{
	asio::io_context io;
	SyncTcpClient client(io, "127.0.0.1", "9999");
	client.connect();
	string msg;
	printf("please send msg:\n");
	while (getline(std::cin, msg))
	{
		printf("getline msg=%s\n", msg.c_str());
		client.syncSend(msg);
	}
	return 0;
}

