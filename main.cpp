#include <iostream>
#include <thread>
#include "boost/asio.hpp"
using namespace boost::asio;
int main() {
    io_service service;
    ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
    ip::tcp::socket sock(service);
    sock.connect(ep);
    return 0;
}