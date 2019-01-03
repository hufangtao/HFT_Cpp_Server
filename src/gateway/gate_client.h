#ifndef GATE_CLIENT_H
#define GATE_CLIENT_H

#include <boost/asio.hpp>
using boost::asio::ip::tcp;


/**
 * 一个client对应一个客户端链接
*/
class gate_client
{
  public:
    gate_client(tcp::socket socket);
    void start();

  private:
    tcp::socket socket_;
};

#endif