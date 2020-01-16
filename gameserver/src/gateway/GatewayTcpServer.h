#ifndef GATEWAY_TCP_SERVER_H
#define GATEWAY_TCP_SERVER_H

#include <list>
#include "GatewayTcpAcceptor.h"

/**
 * 负责生成多个linstener（acceptor）
*/
class GatewayTcpServer
{
  private:
    static std::list<GatewayTcpAcceptor> acceptors;

  public:
    GatewayTcpServer();
    ~GatewayTcpServer();

    static void listen_tcp_port(boost::asio::io_context &io_context, int port);
};

#endif
