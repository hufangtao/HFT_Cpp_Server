#ifndef GATEWAY_TCP_ACCEPTOR_H
#define GATEWAY_TCP_ACCEPTOR_H

#include "GateClient.h"

/**
 * 负责监听端口传过来的链接请求：异步accpet
 * 当成功接受了之后，启动一个新的client对用消息收发
*/
class GatewayTcpAcceptor
{
public:
  GatewayTcpAcceptor(boost::asio::io_context &io_context,
                       const tcp::endpoint &endpoint);

private:
  void do_accept();

  tcp::acceptor acceptor_;
};

#endif