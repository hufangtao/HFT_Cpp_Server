#include "GatewayTcpServer.h"

std::list<GatewayTcpAcceptor> GatewayTcpServer::acceptors;

GatewayTcpServer::GatewayTcpServer()
{
}
GatewayTcpServer::~GatewayTcpServer()
{
}

void GatewayTcpServer::listen_tcp_port(boost::asio::io_context &io_context, int port)
{
    tcp::endpoint endpoint(tcp::v4(), port);
    GatewayTcpServer::acceptors.emplace_back(io_context, endpoint);
}
