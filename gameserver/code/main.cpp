#include "player.h"
#include "timer.h"

void run_io(asio::io_context* io)
{
	io->run();
}

int main()
{
    asio::io_context io;
    Timer timer(io);
	std::thread t1(&run_io, &io);
    io.run();
	t1.join();
    return 0;
}

