#ifndef GATECLIENT_H
#define GATECLIENT_H

#include <iostream>
#include <google/protobuf/message.h>
#include <common/protomessage/ProtoMessage.h>
#include <boost/asio.hpp>

#include "common/utils/ProtoUtils.h"
#include "common/utils/common.h"

using boost::asio::ip::tcp;

class PlayerServer;
/**
 * 一个client对应一个客户端链接
*/
class GateClient : public std::enable_shared_from_this<GateClient>
{
  public:
    GateClient(tcp::socket socket);
    void start();
    void set_player_server(std::shared_ptr<PlayerServer> playerServer);

  private:
    std::shared_ptr<PlayerServer> playerServer;
    // PlayerServer* playerServer;
    tcp::socket socket_;
    ProtoMessage read_msg_;
    void do_read_header();
    void do_read_body();
    void do_write();
};

#endif