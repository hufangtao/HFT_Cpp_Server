#ifndef GATECLIENT_H
#define GATECLIENT_H

#include <common/protomessage/ProtoMessage.h>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

/**
 * 一个client对应一个客户端链接
*/
class GateClient
{
  public:
    GateClient(tcp::socket socket);
    void start();

  private:
    tcp::socket socket_;
    ProtoMessage read_msg_;
    void do_read_header();
    void do_read_body();
    void do_write();
};

#endif