#include <iostream>
#include <list>
#include "asio/chat/chat_server.h"

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 2)
        {
            std::cerr<< "Usage:chat_server <port>[<port> ...]\n";
            return 1;
        }
        boost::asio::io_context io_context;
        std::list<chat_server> servers;
        for (int i = 1; i < argc; ++i)
        {
            tcp::endpoint endpoint(boost::asio::ip::address().from_string("192.168.1.104"), short(std::atoi(argv[i])));
            servers.emplace_back(io_context, endpoint);
            std::cout<<endpoint.address()<<":"<<endpoint.port()<<":      chat server started\n";
        }
        io_context.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}