#include "gateway_tcp_server.h"

gateway_tcp_server::gateway_tcp_server()
{
}
gateway_tcp_server::~gateway_tcp_server()
{
}

void gateway_tcp_server::listen_tcp_port(boost::asio::io_context &io_context, int port)
{
    tcp::endpoint endpoint(tcp::v4(), port);
    acceptors.emplace_back(io_context, endpoint);
}
