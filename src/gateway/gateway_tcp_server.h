#ifndef GATEWAY_TCP_SERVER_H
#define GATEWAY_TCP_SERVER_H

#include <list>
#include "gateway_tcp_acceptor.h"

/**
 * 负责生成多个linstener（acceptor）
*/
class gateway_tcp_server
{
  private:
    std::list<gateway_tcp_acceptor> acceptors;

  public:
    gateway_tcp_server();
    ~gateway_tcp_server();

    void listen_tcp_port(boost::asio::io_context &io_context, int port);
};

#endif
