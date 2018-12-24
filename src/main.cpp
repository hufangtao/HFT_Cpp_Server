#include <iostream>
#include <time.h>
#include <boost/asio.hpp>
#include "asio/multicast/receiver.cpp"
using boost::asio::ip::tcp;

int main(int argc, char *argv[])
{
    
    try
    {
        /* code */
        if(argc!=3){
            std::cerr<<"Usage: receiver <listen_address> <multicast_address>\n";
            std::cerr<<"For IPv4, try:\n";
            std::cerr<<"    receiver 0.0.0.0 239.255.0.1\n";
            std::cerr<<"For IPv6 try:\n";
            std::cerr<<"    receiver 0::0 ff31::8000:1234\n";
            return 1;
        }

        boost::asio::io_context io_context;
        receiver r(io_context, boost::asio::ip::make_address(argv[1]), boost::asio::ip::make_address(argv[2]));
        io_context.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}