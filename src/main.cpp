#include <iostream>
#include "asio/chat/chat_server.h"
#include <time.h>

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Usage:chat_server <port>[<port> ...]\n";
            return 1;
        }
        boost::asio::io_context io_context;
        std::list<chat_server> servers;
        for (int i = 1; i < argc; ++i)
        {
            tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
            servers.emplace_back(io_context, endpoint);
        }
        io_context.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}