#include "timer.h"
#include "sync_tcp_client.h"

int main()
{
	asio::io_context io;
	SyncTcpClient client(io, "127.0.0.1", "9999");
	client.connect();
	auto t1 = std::thread([&](){io.run();});
	string msg;
	printf("please send msg:\n");
	while (getline(std::cin, msg))
	{
		printf("getline msg=%s\n", msg.c_str());
		client.syncSend(msg);
	}
	
	t1.join();
	return 0;
}

